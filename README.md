Arduino Auto Flusher
====================

This is an automatic touchless flusher controlled by Arduino to be installed in a toilet, shower or a kitchen sink. It consists of an Arduino Nano, a PIR sensor, a relay and a 12V solenoid valve. When the object is out of sight of the PIR, the microcontroller waits a defined amount of time while blinking the LED, then opens a relay for some time, so the water can flush. Each operation is logged to the Serial port.

The sketch is using only 3322 bytes (10%) of the flash memory.

Schematic
---------

The PIR detector (upper right) is connected to the pin 4 (+5V output) and 5 (digital input). The relay (lower right) is connected to the pin 2 (+5V output) and 3 (digital output). The MCU (left) has an onboard LED at pin 13 (digital output).

![Connection schematic](https://github.com/niutech/arduino-auto-flusher/raw/master/schematic.jpg)

The breadboard in the case:

![Controller in the case](https://github.com/niutech/arduino-auto-flusher/raw/master/controller.jpg)

The 12V water solenoid valve (normally closed):

![Solenoid valve](https://github.com/niutech/arduino-auto-flusher/raw/master/valve.jpg)

Enhancements
------------

The project could possibly be enhanced by logging the data to some server via Wi-Fi, Ethernet or Bluetooth, using an MQTT or CoAP protocol, thus making an Internet-of-Things toilet!

Author and license
------------------

Arduino Auto Flusher is made by Jerzy Głowacki under the MIT License.