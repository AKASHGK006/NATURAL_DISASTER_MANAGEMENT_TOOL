int relay = 4;
int relay1 = 5;
int LED =13;

void loop()
{
  gas();
  hot();
  water();
}


void setup()
{
  Serial.begin(9600); 
  pinMode(relay, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(LED, OUTPUT);
}

void gas()
{
  int data = analogRead(A0);
  delay(1000);
  if ( data >= 80)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(relay, HIGH);
    Serial.println("GAS_DETECTED");
    delay(1000);
  }
  else
  {
    digitalWrite(LED, LOW);
    digitalWrite(relay, LOW);
    Serial.println("GAS_NOT_DETECTED");
  }
}

void hot()
{
  int Flame_detected = digitalRead(3);
  if (Flame_detected == 0)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(relay1, LOW);
    Serial.println("FLAME_DETECTED");
    delay(1000);
  }
  
  else
  {
    digitalWrite(LED, LOW);
    digitalWrite(relay1, HIGH);
    Serial.println("FLAME_NOT_DETECTED");
  }
}


void water()
{
  int value = analogRead(A1);
  if (value > 200) 
  {
    digitalWrite(LED, HIGH);
    Serial.println("ALERT_WATER_LEVEL_IS_HIGH");
    delay(1000);
  }  
    
   else 
   {
     digitalWrite(LED, LOW);
     Serial.println("WATER_LEVEL_IS_LOW");  
     Serial.println("&");  
   }
}
