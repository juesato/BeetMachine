# Beet Machine

A beat machine made out of beets. Based on the code for the [peach machine](https://www.youtube.com/watch?v=C7NaFOBrhP8).

[DEMO]

`ArduinoPeaches` contains the Arduino code to detect touch. `PeachesSoundboard` contains a Python script that communicates with the Arduino using the [pyserial](http://pyserial.sourceforge.net/pyserial_api.html) library. 

This hack relies on the Arduino [CapacitiveSensor](http://playground.arduino.cc/Main/CapacitiveSensor) library, which also has a decent explanation of the underlying capacitive sensing technology for detecting touches.

## Setup

 1. Clone the repository
 2. Arrange Arduino on breadboard as explained in the Breadboard section.
 3. Upload `ArduinoPeaches.ino` to Arduino through USB.  You likely will have to add the Arduino [CapacitiveSensor](http://playground.arduino.cc/Main/CapacitiveSensor) library first.
 4. Plug in Arduino through USB. 
 5. Run `python soundboard.py [PORT]` with the appropriate serial port. This should look something like `/dev/ttyACM1` on Linux, or `COM1` on Windows.
 6. You should be able to make beats by pinching the lead wires now.


### Dependencies

Arduino:

Add [CapacitiveSensor](http://playground.arduino.cc/Main/CapacitiveSensor) library.

Python:
```
juesato@juesato:~$ sudo apt-get install python-pyaudio
juesato@juesato:~$ sudo apt-get install python-pygame
```

## Breadboard

Here is a picture of my breadboard. 

[PICTURE]

in 2 is the send pin, which is hooked up to the 5V rail so that it's easy to connect to many receive pins at once. The current goes through a ~200 kOhm resistor to the receive pin. 

After the resistor is a wire with the other end attached to a beet, which can be touched to trigger the sensor. You can also pinch the wires directly to trigger them.

## Sample Tracks

Hopefully I'll get around to making some arrangements which can be played with this.