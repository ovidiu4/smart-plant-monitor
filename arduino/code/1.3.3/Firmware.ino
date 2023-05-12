int check_version(){
  Serial.println("Checking for updates");
  WiFiClientSecure client;
  client.setInsecure();
  HTTPClient http;
  http.setTimeout(http_timeout);
  http.begin(client, version_file);
 
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0 && httpResponseCode<300) {
    //Serial.print("HTTP Response code: ");
    //Serial.println(httpResponseCode);
    server_version = http.getString();
    server_version.trim();
    Serial.print("  Server version: ");
    Serial.print(server_version);
    Serial.print(" (Own version: ");
    Serial.print(own_version);
    Serial.println(")");
    if(own_version != server_version){
      Serial.println("  Update required");
      firmware_status = "UPDATE REQUIRED";
      http.end();
      return 1;
    }
    else{
      Serial.println("  No update required");
      firmware_status = "NO UPDATE REQUIRED";
      http.end();
      return 0;
    }
  }
  else {
    Serial.print("  Error code: ");
    Serial.println(httpResponseCode);
    firmware_status = "VERSION NOT FOUND ("+String(httpResponseCode)+")";
    http.end();
    return -1;
  }
  // Free resources
  
  http.end();
  return 0;
}


int check_firmware(){
  Serial.print("Checking firmware file: ");
  WiFiClientSecure client;
  client.setInsecure();
  HTTPClient http;
  http.setTimeout(http_timeout);
  http.begin(client, firmware_file);
 
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0 && httpResponseCode<300) {
    firmware_status = "UPDATE AVAILABLE";
    Serial.println("OK");
    return 1;
  }
  else {
    Serial.print("  Error code: ");
    Serial.println(httpResponseCode);
    http.end();
    firmware_status = "FIRMWARE NOT FOUND ("+String(httpResponseCode)+")";
    return -1;
  }
  // Free resources
  
  http.end();
  return 0;
}


void update_firmware(){
  
  perform_update = false;
  
  for (int i = 1; i <= 10; i++) {
    digitalWrite(external_led_pin, LOW);
    delay(50);
    digitalWrite(external_led_pin, HIGH);
    delay(50);
  }
  
  Serial.println("*** UPDATING FIRMWARE ***");
    
  Serial.print("Checking tree file: ");
  WiFiClientSecure client;
  client.setInsecure();
  HTTPClient http;
  http.setTimeout(http_timeout);
  http.begin(client, tree_file);
 
  String payload = ""; 
  String lines[20];
  String newline[] = { "\r\n", "\r", "\n" };
  int StringCount = 0;
  int index;
  
  int httpResponseCode = http.GET();
  if (httpResponseCode>0 && httpResponseCode<300) {
    
    Serial.println("OK");

    /*
    Serial.print("Formatting storage: ");
    bool formatted = SPIFFS.format();
    if(formatted){
      Serial.println("OK");
    }else{
      Serial.println("Failed");
    }
    */
    
    payload = http.getString();
    
    //Serial.println(payload.length());
    //Serial.println(payload);
    
    while (payload.length() > 0)
    {
      index = payload.indexOf("\r\n");
      if (index == -1) // No space found
      {
        lines[StringCount] = payload;
        lines[StringCount].trim();
        StringCount++;
        break;
      }
      else
      {
        lines[StringCount] = (payload.substring(0, index));
        lines[StringCount].trim();
        //Serial.println(lines[StringCount]);
        StringCount++;
        payload = payload.substring(index+1);
      }
    }
    
    Serial.println("Downloading Github data files: ");
    
    // Show the resulting substrings
    for (int i = 0; i < StringCount; i++)
    {
      digitalWrite(external_led_pin, HIGH);
      
      WiFiClientSecure client;
      client.setInsecure();
      HTTPClient http;
      http.setTimeout(http_timeout);
      http.begin(client, github_data_path + String(lines[i]));
      int httpResponseCode = http.GET();

      Serial.print("  ");
      Serial.print(lines[i]);
      Serial.print(": ");
      Serial.println(httpResponseCode);

      digitalWrite(external_led_pin, LOW);
      File file = SPIFFS.open("/" + lines[i], FILE_WRITE);
     
      if (!file) {
        Serial.println("  There was an error opening the file for writing");
        return;
      }
      if (file.print(http.getString())) {
        Serial.println("    File was written");
      } else {
        Serial.println("    File write failed");
      }
     
      file.close();
  
    }
  
  }

  digitalWrite(external_led_pin, HIGH);
  Serial.print("Downloading firmware!");
  ESPhttpUpdate.update(firmware_file);

  //These will never print!
  Serial.println("OK");
  Serial.println("*** UPDATE COMPLETE ***");

}
