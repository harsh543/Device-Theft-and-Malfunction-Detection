#include <math.h>
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
const int sensor=A0; //set the sensor to pin A0
const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A3;     // Grove - Temperature Sensor connect to A0
const int buzzerPin = A2;
const int buzzerPin1 = A1;
const int ledPin1 = 12;
const int ledPin2 = 13;
int counter =0;
void setup(){
  pinMode(buzzerPin, OUTPUT);
  pinMode(buzzerPin1, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);//initialize the serial monitor at 9600 baud rate
  
}

void loop(){
  int sensorValue=analogRead(sensor);//create a var to store the value of the sensor
  
  if(sensorValue > 300) 
  {
  Serial.print("light= ");//print on the serial monitor what's in the ""
  Serial.println(sensorValue);// print the value of the sensor on the serial monitor
  beep(f, 100);  
  
 
 
  }
  else{
  Serial.print("light =");//print on the serial monitor what's in the ""
  Serial.println(sensorValue);// print the value of the sensor on the serial monitor
 
  }
  int a = analogRead(pinTempSensor);
  float R = 1023.0/a-1.0;
  R = R0*R;
  float initial_temperature = 43.0;
  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
  Serial.print("temperature =");
  Serial.println(temperature);
  if((temperature -  initial_temperature) > 6)
  {
     beep1(cSH, 100);  
    
 
  //delay(500);  
  }
  delay(1000);
}
void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
  digitalWrite(ledPin1, LOW);
  delay(duration);
  noTone(buzzerPin);
   /*//Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, LOW);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }*/
   //digitalWrite(ledPin1, LOW);
  //Stop tone on buzzerPin
  
 
  delay(1);
 
  //Increment counter
  //counter++;
}

void beep1(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin1, note, duration);
  digitalWrite(ledPin1, LOW);
  delay(duration);
  noTone(buzzerPin1);
   /*//Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, LOW);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }*/
   //digitalWrite(ledPin1, LOW);
  //Stop tone on buzzerPin
  
 
  delay(1);
 
  //Increment counter
  //counter++;
}
