String processor(const String& var)
{ 
  if(var == "macaddress"){
    return WiFi.macAddress();
  }
  if(var == "software_version"){
    return own_version;
  }
  if(var == "server_software_version"){
    return server_version;
  }
  if(var == "savedssid"){
    return eeprom_ssid;
  }
  if(var == "savedpassword"){
    return eeprom_password;
  }
  if(var == "batteryvoltage"){
    return String(battery_voltage);
  }
  if(var == "hostname"){
    return String(hostname);
  }
  if(var == "wifimessage1"){
    if(wifi_status == false && wifi_saved_eeprom == false){
      return String("<b><font color = \"red\">COULD NOT CONNECT WIFI</font></b>");
    }
    if(wifi_saved_eeprom == true){
      return String("<b><font color = \"red\">WIFI SETTINGS CHANGED</font></b>");
    }
    if(wifi_status == true && wifi_saved_eeprom == false){
      return String("<b>Connected to WIFI:</b>");
    }
  }
  if(var == "wifimessage2"){
    if(wifi_status == false && wifi_saved_eeprom == false){
      return String("<b><font color = \"red\">PLEASE CHECK SETTINGS</font></b>");
    }
    if(wifi_saved_eeprom == true){
      return String("<b><font color = \"red\">RESTART REQUIRED</font></b>");
    }
    if(wifi_status == true && wifi_saved_eeprom == false){
      return String(WiFi.SSID());
    }
  }
  if(var == "wifi_networks"){
    return String(wifi_networks);
  }
  if(var == "wifi_saved_eeprom"){
    if(wifi_saved_eeprom == true){
      return String("RESTART REQUIRED");
    }
  }
  if(var == "restart_button_value"){
    if(restarting == false){
      return String("RESTART");
    }
    if(restarting == true){
      return String("** RESTARTING **");
    }
  }
  if(var == "battery_voltage"){
    return String(battery_voltage);
  }
  if(var == "battery_temperature"){
    return String(String(board_temperature)+char(176)+"C");
  }

  if(var == "soil_temperature"){
    if(soil_temperature < -30){
      return String("ERR");
    }else{
      return String(String(soil_temperature)+char(176)+"C");
    }
  }
  
  if(var == "soil_humidity"){
    return String(soil_humidity_percent);
  }
  
  if(var == "bus_voltage"){
    return String(bus_voltage);
  }
  if(var == "air_temperature"){
    return String(String(air_temperature)+char(176)+"C");
  }
  if(var == "air_humidity"){
    return String(air_humidity);
  }
  if(var == "ambient_light"){
    return String(ambient_light) + " Lux";
  }
  if(var == "ir_light"){
    return String(ir_light) + " Lux";
  }
  if(var == "connection_status"){
    if(home_assistant_connection == false){
      return String("FAILED (" + String(test_connection_code) +")");
    }
    if(home_assistant_connection == true){
      return String("SUCCESSFUL (" + String(test_connection_code) +")");
    }
  }
  if(var == "firmware_status"){
    return String(firmware_status);
  }

  if(var == "firmware_button"){
    if(firmware_code == 1){
      return String("UPDATE");
    }
    else{
      return String("REFRESH");
    }
  }
  
  if(var == "board_check"){
    if(board_check == false){
      return String("DISCONNECTED");
    }
    if(board_check == true){
      return String("CONNECTED");
    }
    
  }
  
  return String();
}
