const int Trigger = 10;
const int Echo = 11;
int buzzer=7;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  long duration, cm;
  pinMode(Trigger, OUTPUT);
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(Trigger, LOW);
  pinMode(Echo, INPUT);
  duration = pulseIn(Echo, HIGH);
  cm = microsecondsToCentimeters(duration);

  if(cm<=60)
  {
    tone(buzzer,700,90);
  }
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(1000);
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}


