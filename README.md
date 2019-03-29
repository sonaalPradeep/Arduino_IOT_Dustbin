Arduino IOT Project
===================
###### project by Sonaal P. Pradeep

### Introduction

An ancient chinese proverb says that...
 > "There are many paths, but the only one that leads to the top of the mountain, is the one you make yourself."


This project was made for our Environmental Studies course, to show that there are many ways CSED students could implement solutions to help save the environment. Our project involved implementing a very simple version of the 'smart bin', the new and modern dustin which were implemented in Singapore, and yet to be deployed in other places around the world. The original dustbins were more advanced, having solar panels, transmitters, compressors to mention some of them. But with this project, I wish to implement just the basic operation, which is to send a message to your phone if the dustbin gets close to getting filled. Other minor features were added later on.

### Implementation

For this project, I used...
1. Arduino Uno
2. 9V Battery
3. Bluetooth module (HC-05)
4. Ultrasonic sensor (HC-SR04)
5. Temperature and Humidity Sensor (DHT11)
7. Button Switch (Optional)
6. Tilt Switch
7. Breadboard
8. Connecting wires
9. LED's (1 Red and 1 Green)
10. Resistors

The following connections are made (ignoring the obvious ones which need only the Vcc and Gnd connected):
Trig pin of ultrasonic sensor : 13
Echo pin of ultrasonic sensor : 12
Red LED                       : 11
Green LED                     : 10
Tilt Switch                   : 8
Signal Pin of temp. sensor    : A0
Bluetooth Rx                  : Tx
Bluetooth Tx                  : Rx
Button Switch                 : Reset

Ensure that the LED's and the tilt switch is connected with resistors. 

Upload the code to the arduino board. (Note! : The Rx port needs to be open while uploading the program).

Connect the bluetooth module to your phone (use any Arduino Bluetooth Controller App).

Press the reset button to start the program from the top.

### Working of the program
After starting the program, both the red and the green LED's will glow. This indicates that the controller hasn't been configured for the dustbin, and needs to be done so.

Configure the microcontroller for a dustbin by pressing the '0' key when prompted to. This will find the size of the dustbin(in terms of 'cms' of capacity). Now only the green LED will glow. This indicated that the current state of the dustbin is good.

A dustbin is said to be in a good mood if the green LED is on, and is said to be in a bad mood if the red LED is on.

Pressing the '1' key after this will return the fill capacity in percentage. 

Pressing the '2' key resets the dustbin to a good mode. This can be used to reset the dustbin after it has been cleaned, but it can also be fixed by pressing the '1' key.

Pressing the '3' key resets the microcontroller to its factory settings. If the button switch is installed, press it to obtain similar results.

The DHT11 module is primarily used for monitoring the temperature, although it can even return the humidity as well. The board has been set up to return a warning and caution message if the temperature rises above 40°C or the humidity rises above 85%. Both are high deviations from normal conditions, wherein a temperature rise above 40°C could imply a fire in the dustbin caused, for example, by a cigarette. 

### Scope for possible upgrades

* Using a GSM, Wifi module would make it more convenient, so that the app needn't always be connected to the bluetooth module. Using an RF module would give it longer range, but requires a line of sight.
* A seperate app, which would eventually lead to ways for further development.

### Conclusions

* I have learnt a lot from the development of this program. I've learnt how to use the arduino board effectively, and have tried to use the modules to the best of its capabilities.
* I was able to understand that anyone who has the vision to do something for the society or the environment around them, and takes the first few steps will always set an example to the people around them. Saving the environment is not limited to just a few set of people, it is the responsibility of an individual. And it is the responsibility of an individual to set an example.
