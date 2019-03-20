// -------------------------------------------------------------------//
//                | IOT ARDUINO GARBAGE LEVEL DETECTOR |              //
// -------------------------------------------------------------------//

/* by Sonaal P. Pradeep
   IOT Arduino Garbage Level Detector project for our Enivormental Studies Course.
   The primary aim of this project is to show that computer science students can do something; either build hardware or code software to help save nature, or the environment around us.
   This project implements a IOT based dustbin, which detects the fill level of a dustbin and send a message to whom-so-ever incharge.
*/

#include "dht.h"

#define pTemp A0
#define pTrig 13
#define pEcho 12
#define lRed 11
#define lGreen 10
#define tSwitch 8

dht DHT;

float capacity = 0.0;
bool msg = false;

void setup() {
  Serial.begin(9600);
  pinMode(pTrig, OUTPUT);
  pinMode(pEcho, INPUT);
  pinMode(lRed, OUTPUT);
  pinMode(lGreen, OUTPUT);
  pinMode(tSwitch, INPUT);
}

void loop() {
  char ch;
  float temp;
  float distance, percent;

  while(digitalRead(tSwitch) == LOW)
  {
    Serial.println("HELP ME! I'VE FALLEN");
    delay(100);
  }
  
  if(msg == false)
  {
    digitalWrite(lRed, LOW);
    if(capacity == 0)
      digitalWrite(lRed, HIGH);
    
    digitalWrite(lGreen, HIGH);
  }
  
  WARN:
  
  DHT.read11(pTemp);

  if(DHT.temperature > 40)
  {
    Serial.println("WARNING! HIGH TEMPERATURE DETECTED.");
    Serial.print("TEMPERATURE : ");
    Serial.print(DHT.temperature);
    Serial.println(" C");
    digitalWrite(lGreen, LOW);
    digitalWrite(lRed, HIGH);
    delay(500);
    digitalWrite(lRed, LOW);
    delay(500);
    goto WARN;
  }

  if(DHT.humidity > 85)
  {
    Serial.println("CAUTION! HIGH HUMIDITY DETECTED.");
    Serial.print("HUMIDITY : ");
    Serial.print(DHT.humidity);
    Serial.println("%");
    digitalWrite(lGreen, LOW);
    digitalWrite(lRed, HIGH);
    delay(500);
    digitalWrite(lRed, LOW);
    delay(500);
    goto WARN;
  }

  Serial.println("--------------------------------------------");
  delay(100);
  Serial.println("Garbage Level Detector");
  delay(250);
  Serial.println("Select from one amongst the following : ");
  delay(250);
  Serial.println("0. Configure the board for a new dustbin");
  delay(250);
  Serial.println("1. Display fill level");
  delay(250);
  Serial.println("2. Reset the LED status");
  delay(250);
  Serial.println("3. Reset completely");
  delay(250);
  Serial.println("--------------------------------------------");
  delay(250);

  FRONT:
  ch = Serial.read();

  if (ch == '0')
  {
      Serial.println("Reconfiguring dustbin");
      delay(100);
      if(capacity == 0)
      {
        Serial.println("New dustbin");
        delay(100);
      }
        
      else
      {
        Serial.print("Old size of dustbin : ");
        delay(100);
        Serial.print(capacity);
        delay(100);
        Serial.println(" cms");
        delay(100);
      }

      capacity = triggerPulse();

      Serial.print("New size of dustbin : ");
      delay(100);
      Serial.print(capacity);
      delay(100);
      Serial.println(" cms");  
      delay(100);    
  }
  else if (ch == '1')
  {
      Serial.println("Fill level");
      delay(100);

      if(capacity == 0)
      {
        Serial.println("ERROR! CAPACITY OF DUSTBIN NOT SET.");
        delay(100);
        Serial.println("Please press '0' to proceed");
        delay(100);
        goto FRONT;
      }

      distance = triggerPulse();
      percent = (capacity - distance) / capacity;

      percent = percent * 100;

      if(percent < 0 || percent > 100)
      {
        Serial.println("UNEXPECTED ERROR!");
        delay(100);
        Serial.println("Please try again");
        delay(100);

        goto WARN;
      }
      
      delay(100);
      Serial.print("Current level : ");
      delay(100);
      Serial.print(percent);
      delay(100);
      Serial.println(" %");

      if(percent > 75 && msg == false)
      {
        digitalWrite(lRed, HIGH);
        digitalWrite(lGreen, LOW);

        msg = true;
      }
      else if(percent < 25 && msg == true)
        msg = false;
  }
  else if(ch == '2')
  {
    distance = triggerPulse();
    percent = (capacity - distance) / capacity;

    percent = percent * 100;

    if(percent > 75)
    {
      Serial.println("CAUTION! CAPACITY ALMOST FULL.");
      delay(100);
      Serial.println("If dustbin is empty, please check for any debris covering the sensor");
      delay(100);
    }
    else
      msg = false;
  }
  else if(ch == '3')
  {
    Serial.println("RESET");
    capacity = 0;
    msg = false;
  }
  else
      goto FRONT;

  ch = " ";

  delay(250);
}

long triggerPulse()
{
      long res, duration, distance;
      digitalWrite(pTrig, LOW);
      delayMicroseconds(2);
      digitalWrite(pTrig, HIGH);
      delayMicroseconds(10);
      digitalWrite(pTrig, LOW);

      duration = pulseIn(pEcho, HIGH);
      distance = (duration / 2.0) / 29.1;

      return distance;
}
