# ESP32 Powered Smart Plant Monitor



**Hello. This project is ongoing, therefore changes will be frequent.**

![](https://github.com/ovidiu4/smart-plant-monitor/blob/main/testing/20230305_194624.jpg)
![](https://github.com/ovidiu4/smart-plant-monitor/blob/main/3D%20render/Schematic_Plant%20Monitor%20SMD%20V2_2023-03-12.png)

Overall features:
- Low power and small size (45x45x10mm)
- Rechargeable and programable with Arduino
- By adding a USB port to a small solar panel you've created a simple add-on 
- Can communicate via WIFI or Bluetooth
- One device can stay plugged in all the time (act as hub) while the others send updates to it (low power mode)

Back of the main board. Features:
- ESP32-S3 supports capacitance measuring directly, through the touchpad circuitry
- TP4056 charging + protection circuit
- USB C with 5.1K resistors added
- 3.3V LDO for powering everything
- Circuitry for a 1.54" E-Paper display (goes on the back)
- AHT20 IC for local air humidity and temperature measurement
- Card edge connector for easy and cheap "soil probe" PCB swap
- 2 GPIO buttons (one connected to GPIO0) and 1 status LED

![](https://github.com/ovidiu4/smart-plant-monitor/blob/main/3D%20render/face_1.2.PNG)


Front of the main board. Features:
- Battery on-off switch
- I2C header for possible module addition
- E-Paper display
- Slim LiPo battery goes under the display. Could fit up to 4x40x30mm (usually 450-500mAh)

![](https://github.com/ovidiu4/smart-plant-monitor/blob/main/3D%20render/back_1.2.PNG)

Soil probe. Features:
- No components and connectors added, just the bare PCB
- Cheap and easy to replace when they eventually breakdown in the soil
- Solder pads avaialble if you'd like to add a 0603 component (LED or Thermistor for soil surface temperature). Connected to GPIO through a 2K resistor
- Can be in any size and shape you'd like as long as the top matches the conector (calibration and adjustments are done in software)

![](https://github.com/ovidiu4/smart-plant-monitor/blob/main/3D%20render/probe.PNG)
