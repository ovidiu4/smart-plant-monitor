void send_data_home_assistant(){

  Serial.println("*** SENDING DATA ***");
  WiFiClientSecure client;
  client.setInsecure();
  String httpRequestData = "";
  int httpResponseCode = 0;
  HTTPClient http;

  apiKey = "Bearer " + apiKey;
  Serial.print("  URL: ");
  Serial.println(home_assistant_url);
  Serial.print("  API: ");
  Serial.println(apiKey);
  
  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_air_temperature);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(air_temperature)+"\", \"attributes\": {\"unit_of_measurement\": \"°C\",\"friendly_name\": \""+hostname+" Air Temperature\",\"icon\": \"mdi:thermometer\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);

  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_air_humidity);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(air_humidity)+"\", \"attributes\": {\"unit_of_measurement\": \"%\",\"friendly_name\": \""+hostname+" Air Humidity\",\"icon\": \"mdi:water-percent\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);
  
  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_battery_percent);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(battery_percent)+"\", \"attributes\": {\"unit_of_measurement\": \"%\",\"friendly_name\": \""+hostname+" Battery Percent\",\"icon\": \"mdi:current-dc\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);

  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_battery_voltage);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(battery_voltage)+"\", \"attributes\": {\"unit_of_measurement\": \"V\",\"friendly_name\": \""+hostname+" Battery Voltage\",\"icon\": \"mdi:current-dc\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);

  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_board_temperature);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(board_temperature)+"\", \"attributes\": {\"unit_of_measurement\": \"°C\",\"friendly_name\": \""+hostname+" Board Temperature\",\"icon\": \"mdi:thermometer\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);

  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_bus_voltage);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(bus_voltage)+"\", \"attributes\": {\"unit_of_measurement\": \"V\",\"friendly_name\": \""+hostname+" Bus Voltage\",\"icon\": \"mdi:current-dc\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);

  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_soil_moisture_face);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(soil_face_value)+"\", \"attributes\": {\"unit_of_measurement\": \"pF\",\"friendly_name\": \""+hostname+" Face Capacitance\",\"icon\": \"mdi:current-dc\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);

  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_soil_moisture_back);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(soil_back_value)+"\", \"attributes\": {\"unit_of_measurement\": \"pF\",\"friendly_name\": \""+hostname+" Back Capacitance\",\"icon\": \"mdi:current-dc\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);

  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_soil_moisture_percent);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(soil_humidity_percent)+"\", \"attributes\": {\"unit_of_measurement\": \"%\",\"friendly_name\": \""+hostname+" Soil Moisture Percent\",\"icon\": \"mdi:water-percent\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);

  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_soil_temperature);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(soil_temperature)+"\", \"attributes\": {\"unit_of_measurement\": \"°C\",\"friendly_name\": \""+hostname+" Soil Temperature\",\"icon\": \"mdi:thermometer\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);

  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_ambient_light);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(ambient_light)+"\", \"attributes\": {\"unit_of_measurement\": \"Lux\",\"friendly_name\": \""+hostname+" Ambient Light\",\"icon\": \"mdi:weather-sunny\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);

  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_ir_light);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(ir_light)+"\", \"attributes\": {\"unit_of_measurement\": \"Lux\",\"friendly_name\": \""+hostname+" IR Light\",\"icon\": \"mdi:weather-sunny\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);

  http.begin(client, home_assistant_url+"/api/states/sensor." + hostname + plant_monitor_version);
  http.addHeader("Authorization", apiKey);
  http.addHeader("Content-Type", "application/json");
  httpRequestData = "{\"state\": \""+String(own_version)+"\", \"attributes\": {\"friendly_name\": \""+hostname+" Firmware Version\",\"icon\": \"mdi:counter\"}}";           
  httpResponseCode = http.POST(httpRequestData);
  Serial.println(httpResponseCode);
  http.end();
  delay(10);
  
  Serial.println("*** SEND DATA COMPLETE ***");
}
