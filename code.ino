// C++ code
//
int x;
int pir = 11, sonic = 10, echo = 9, trig = 8, gas = A0;
int b1 = 2, b2 = 3, b3 = 4, b4 = 5, stop = 6;
  
void setup()
{
  Serial.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pir, INPUT);
  pinMode(echo, INPUT);
  pinMode(gas, INPUT);
  pinMode(trig, OUTPUT);
  
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  pinMode(stop, INPUT);
}

void pirsensor()
{
  x = digitalRead(pir);
  Serial.println(x);
}

void sonic3pin()
{
  pinMode(sonic, OUTPUT);
  digitalWrite(sonic, HIGH);
  pinMode(sonic, INPUT);
  x = pulseIn(sonic, HIGH);
  Serial.println(x);
}

void sonic4pin()
{
  digitalWrite(trig, LOW);
  digitalWrite(trig, HIGH);
  digitalWrite(trig, LOW);
  x = pulseIn(echo, HIGH);
  Serial.println(x);
}

void gassensor()
{
  x = analogRead(gas);
  Serial.println(x);
}

void led()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{  
  if(digitalRead(b1) == HIGH)
  {
    led();
    Serial.println("PIR sensor selected");
    while(digitalRead(stop) == LOW)
    {
      Serial.print("Value: ");
      pirsensor();
    }
    led();
    Serial.println("Stopped and deselected");
  }
  else if(digitalRead(b2) == HIGH)
  {
    led();
    Serial.println("Ultrasonic 3 pin selected");
    while(digitalRead(stop) == LOW)
    {
      Serial.print("Value: ");
      sonic3pin();
    }
    led();
    Serial.println("Stopped and deselected");
  }
  else if(digitalRead(b3) == HIGH)
  {
    led();
    Serial.println("Ultrasonic 4 pin selected");
    while(digitalRead(stop) == LOW)
    {
      Serial.print("Value: ");
      sonic4pin();
    }
    led();
    Serial.println("Stopped and deselected");
  }
  else if(digitalRead(b4) == HIGH)
  {
    led();
    Serial.println("Gas sensor selected");
    while(digitalRead(stop) == LOW)
    {
      Serial.print("Value: ");
      gassensor();
    }
    led();
    Serial.println("Stopped and deselected");
  }
}
