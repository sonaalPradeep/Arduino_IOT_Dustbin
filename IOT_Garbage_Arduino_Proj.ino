#define pTrig 13
#define pEcho 12
#define lRed 11
#define lGreen 10

void setup() {
  Serial.begin(9600);
  pinMode(pTrig, OUTPUT);
  pinMode(pEcho, INPUT);
  pinMode(lRed, OUTPUT);
  pinMode(lGreen, OUTPUT);
}

void loop() {
  long duration, distance;
  
  digitalWrite(pTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pTrig, LOW);
  
  duration = pulseIn(pEcho, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance < 15)
  {
    digitalWrite(lRed,HIGH);
    digitalWrite(lGreen,LOW);
  }
  else
  {
    digitalWrite(lRed,LOW);
    digitalWrite(lGreen,HIGH);
  }
  
  if (distance >= 200 || distance <= 0)
  {
    Serial.println("Out of range");
  }
  else
  {
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  delay(250);
}
