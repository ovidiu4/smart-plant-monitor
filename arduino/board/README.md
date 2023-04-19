**In order to program the board yourself via Arduino IDE you need to create a custom board**

1. Add the contens of boards.txt to your boards file on your computer. It is typically located at:
   "C:\Users\*USER*\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.7\boards.txt"

2. Copy the entire folder "ovidiu4_esp32s3" to the variants folder on your computer. It is typically located at:
   "C:\Users\*USER*\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.7\variants\"
   
3. Restart Arduino and select the custom board "Ovidiu4 Smart Plant Monitor ESP32-S3"

4. Adjust the following settings:

   a. USB Mode: Hardware CDC and JTAG

   b. CPU Frequency: 80MHz

   c. Partition Scheme: Default 4MB with SPIFFS
