Arduino IOT Project
===================
###### project by Sonaal P. Pradeep

### Introduction

An ancient chinese saying says that...
 > "There are many paths, but the only one that leads to the top of the mountain, is the one you make yourself."


This project was made for our Environmental Studies course, to show a way in which CSED students could implement solutions to help save the environment. Our solution was to implement a very simple version of the 'smart bin', the new and modern dustin which were implemented in Singapore. The original dustbin where more advanced, having solar panels, transmitters, compressors to mention some of them. But with this project, I wish to implement just the basic operation, which is to send a message to your phone if the dustbin gets close to getting filled. 

### Implementation

For this project, I used...
1. Arduino Uno
2. Bluetooth module
3. Ultrasonic sensor
4. Breadboard
5. Connecting wires
6. Battery
7. LED's
   

The ultrasonic sensor and the bluetooth module are connected to the microcontroler. Loading the code onto the board will print the distance between the sensor and the pile of trash. Using any arduino bluetooth controller, the fill percentage will be printed on the terminal.


### Changes I wished I could implement

* Using a GSM or a Wifi module would make it more convinient, so that the app needn't always be connected to the bluetooth module.
* A seperate app, which would eventually lead to ways for further development.
