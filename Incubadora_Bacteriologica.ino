
#include <DHT.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8,9 ,10 ,12, 13); //(RS, E, D4,D5, D6, D7)
int pintemp=A0;
int alarma2=5;
int alarma3=6;
int alarma =3;
int tempC; 
int temp1=38;
int temp3=52;
int temp2=42;
int motor1=11;

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup(){
Serial.begin(9600);
lcd.begin(16,2);
analogReference(INTERNAL);
pinMode(alarma,OUTPUT);
pinMode(alarma2,OUTPUT);
pinMode(alarma3,OUTPUT);
dht.begin();
}
void loop(){
  delay(2000);
tempC = analogRead(pintemp); 
tempC = (1.1 * tempC * 100.0)/1024.0;
float humedad = dht.readHumidity(); //Se lee la humedad
float temp = dht.readTemperature(); //Se lee la temperatura
//temperatura
lcd.setCursor(0,0);
lcd.print("Temp:   ");
lcd.setCursor(5,0);  
lcd.print(temp);
lcd.setCursor(10,0);
lcd.print("C");
//humedad
lcd.setCursor(0,1);
lcd.print("Hum: ");
lcd.setCursor(4,1);
lcd.print(humedad);
lcd.setCursor(7,1);
lcd.print(" %");
//alarma
 if (temp >= 39 & temp <= 40){
     
     digitalWrite(3, HIGH);
     
 }
  else{
    digitalWrite(3,LOW);
    delay(1000);}
    
 if (temp >= 43 & temp <= 44){
     digitalWrite(5, HIGH);
  
 }
  else{
    digitalWrite(5,LOW);
    delay(1000);}
    
   if (temp >= 51 & temp <= 53 ){
     digitalWrite(6, HIGH);
     
 }
  else{
    digitalWrite(6,LOW);
    delay(1000);}
  
}
