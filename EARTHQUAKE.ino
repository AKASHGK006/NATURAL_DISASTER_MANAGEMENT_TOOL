#define buzzer 12 
#define x A0 
#define y A1 
#define z A2  

int xsample=0;
int ysample=0;
int zsample=0;
long start;
int b=0;
#define samples 50
#define maxVal 3
#define minVal -3 
#define buzTime 100

void setup() 
{
  Serial.begin(9600); 
  delay(1000);
  pinMode(buzzer, OUTPUT);
  b=0;
  digitalWrite(buzzer, b);
  for(int i=0;i<samples;i++)
  {
    xsample+=analogRead(x);
    ysample+=analogRead(y);
    zsample+=analogRead(z);
  }

  xsample/=samples;
  ysample/=samples;   
  zsample/=samples;   
  
}

void loop() 
{
    int value1=analogRead(x);
    int value2=analogRead(y);
    int value3=analogRead(z);

    int xValue=xsample-value1;
    int yValue=ysample-value2;
    int zValue=zsample-value3;

 

    if(xValue < minVal || xValue > maxVal  || yValue < minVal || yValue > maxVal  || zValue < minVal || zValue > maxVal)
    { 
      if(b == 0)
      start=millis();
       b=1;
    } 

   else if(b == 1)
   {
      if(millis()>= start+buzTime)    
      b=0;
   }
    digitalWrite(buzzer, b);
    Serial.print("x=");
    Serial.println(xValue);
    Serial.print("y=");
    Serial.println(yValue);
    Serial.print("z=");
    Serial.println(zValue);  
    Serial.println(" $");
    delay(1000);
}
