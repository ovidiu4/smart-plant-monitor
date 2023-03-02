# ESP32 Powered Smart Plant Monitor



**Hello. This project is ongoing, therefore changes will be frequent.**



Back of the main board. Features:
- ESP32-S3 supports capacitance measuring directly, through the touchpad circuitry
- TP4056 charging + protection circuit
- USB C with 5.1K resistors added
- 3.3V LDO for powering everything
- Circuitry for a 1.54" E-Paper display (goes on the back)
- AHT20 IC for local air humidity and temperature measurement
- Card edge connector for easy and cheap "soil probe" PCB swap
- 2 GPIO buttons (one connected to GPIO0) and 1 status LED

![](https://github.com/ovidiu4/smart-plant-monitor/blob/main/3D%20render/face.PNG)


Front of the main board. Features:
- Battery on-off switch
- I2C header for possible module addition
- E-Paper display
- Slim LiPo battery goes under the display. Could fit up to 4x40x30mm (usually 450-500mAh)

![](https://github.com/ovidiu4/smart-plant-monitor/blob/main/3D%20render/back.PNG)

Soil probe. Features:
- No components and connectors added, just the bare PCB
- Cheap and easy to replace when they eventually breakdown in the soil
- Solder pads avaialble if you'd like to add a 0603 component (LED or Thermistor for soil surface temperature). Connected to GPIO through a 2K resistor
- Can be in any size and shape you'd like as long as the top matches the conector (calibration and adjustments are done in software)

![](https://github.com/ovidiu4/smart-plant-monitor/blob/main/3D%20render/probe.PNG)
