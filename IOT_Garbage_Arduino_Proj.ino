// -------------------------------------------------------------------//
//                | IOT ARDUINO GARBAGE LEVEL DETECTOR |              //
// -------------------------------------------------------------------//

/* by Sonaal P. Pradeep
   IOT Arduino Garbage Level Detector project for our Enivormental Studies Course.
   The aim of this project is to implement a solution which can be implemented by computer science students.
*/


#define pTrig 13
#define pEcho 12
#define lRed 11
#define lGreen 10

long capacity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pTrig, OUTPUT);
  pinMode(pEcho, INPUT);
  pinMode(lRed, OUTPUT);
  pinMode(lGreen, OUTPUT);
}

void loop() {
  char ch;
  long duration, distance, percent;

  Serial.println("Garbage Level Detector");
  delay(200);
  Serial.println("Select from one amongst the following : ");
  delay(200);
  Serial.println("0. Configure the board for a new dustbin");
  delay(200);
  Serial.println("1. Display fill level");
  delay(200);
  Serial.println("--------------------------------------------");
  delay(200);

  front:
  ch = Serial.read();

  if (ch == '0')
  {
      Serial.println("Reconfiguring dustbin");
      delay(200);
      if(capacity == 0)
      {
        Serial.println("New dustbin");
        delay(200);
      }
        
      else
      {
        Serial.print("Old size of dustbin : ");
        Serial.print(capacity);
        Serial.println(" cms");
      }

      capacity = triggerPulse();

      Serial.print("New size of dustbin : ");
      delay(200);
      Serial.print(capacity);
      delay(200);
      Serial.println(" cms");      
  }
  else if (ch == '1')
  {
      Serial.println("Fill level");

      distance = triggerPulse();
      
      delay(200);
      Serial.print("Current level : ");
      delay(200);
      Serial.print(distance);
      delay(200);
      Serial.println(" cm");
  }
  else
      goto front;

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
      distance = (duration / 2) / 29.1;

      return distance;
}
