#include <SoftwareSerial.h>
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
#include <stdlib.h>
#include <dht.h>
#define dht_dpin A0 
double voltdiv;

int i, j;
dht DHT;
long t1=0, t2=0, t3=0, t4=0;
char buf1[16];
char buf2[16];
char buf3[16];
char buf4[16];


String strvoltdiv;
String stri;
String strj;
String strper;
// replace with your channel's thingspeak API key
String apiKey = "PBXIOLZ4XAY1FDTV";


SoftwareSerial ser(5, 6); // RX, TX

// this runs once
void setup() {                
  // initialize the digital pin as an output.
   lcd.begin(16, 2);
lcd.setCursor(0, 0);
 lcd.print("Sensors ");
 lcd.setCursor(0, 1);
 lcd.print("using IOT");
 delay(2000);
 lcd.clear();
analogReference(DEFAULT);
  // enable debug serial
  Serial.begin(9600);
  // enable software serial
  ser.begin(115200);
// reset ESP8266
  ser.println("AT+RST");
   delay(500);
  ser.println("AT+CWMODE=3");
   delay(500);
  ser.println("AT+CWJAP=\"project\",\"12345678\"");
  delay(500);
   



}
// the loop
void loop() {
   //Serial.println(analogRead(A3));
   DHT.read11(dht_dpin);
      
  

 i=DHT.humidity;
      j =DHT.temperature;


  

voltdiv = mapf(analogRead(A1), 0, 1023, 0, 5); //voltdiv
int per= mapf(voltdiv, 3.5, 4.3, 0, 100); 
 

    
  lcd.setCursor(0, 0);
   lcd.print("V:");
 lcd.print(voltdiv);
 lcd.print("  ");
 lcd.setCursor(8, 0);
   lcd.print("B:");
 lcd.print(per);
 lcd.print(" %  ");
  lcd.setCursor(0, 1);
     lcd.print("H:");
 lcd.print(i);
 lcd.print(" ");
  lcd.setCursor(8, 1);
   lcd.print("T:");
 lcd.print(j);
 lcd.print(" ");

// if(i>80)
//{
//  digitalWrite(A3, LOW);
//  delay(500);
//  digitalWrite(A3, HIGH);
//}
// if(j>39)
//{
//    digitalWrite(3, LOW);
//  delay(500);
//  digitalWrite(3, HIGH);
//}

 
  strvoltdiv = dtostrf(voltdiv*1000, 4, 1, buf1);

// convert to string
 
strper = dtostrf(per, 4, 1, buf2);
  // convert to string

  stri = dtostrf(i, 4, 1, buf3);
strj = dtostrf(j, 4, 1, buf4);
  
  
  Serial.print(strvoltdiv);
  Serial.print(" ");
   Serial.print(strper);
     Serial.print(" ");
    Serial.print(stri);
  Serial.print(" ");
   Serial.print(strj);
 Serial.print(" ");
 
  Serial.println(" ");
  if(millis() - t1>6000)
  {
    t1=millis();
  
  // TCP connection
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  ser.println(cmd);

  if(ser.find("Error")){
    //Serial.println("AT+CIPSTART error");
    return;
  }

  // prepare GET string
  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field1=";
  getStr += String(strvoltdiv);
  getStr += "\r\n\r\n";



  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ser.println(cmd);

   

  if(ser.find(">")){
    ser.print(getStr);
  }
   else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
  // thingspeak needs 15 sec delay between updates
  }
  if(millis() - t2>8000)
  {
    t2=millis();
  
  // TCP connection
  String cmd4 = "AT+CIPSTART=\"TCP\",\"";
  cmd4 += "184.106.153.149"; // api.thingspeak.com
  cmd4 += "\",80";
  ser.println(cmd4);

  if(ser.find("Error")){
    //Serial.println("AT+CIPSTART error");
    return;
  }

  // prepare GET string
  String getStr4 = "GET /update?api_key=";
  getStr4 += apiKey;
  getStr4 +="&field4=";
  getStr4 += String(strper);
  getStr4 += "\r\n\r\n";



  // send data length
  cmd4 = "AT+CIPSEND=";
  cmd4 += String(getStr4.length());
  ser.println(cmd4);

   

  if(ser.find(">")){
    ser.print(getStr4);
  }
   else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
  // thingspeak needs 15 sec delay between updates
  }
    
   if(millis() - t3>3000)
  {
    t3=millis();
  
   // TCP connection
  String cmd2 = "AT+CIPSTART=\"TCP\",\"";
  cmd2 += "184.106.153.149"; // api.thingspeak.com
  cmd2 += "\",80";
  ser.println(cmd2);

  if(ser.find("Error")){
    //Serial.println("AT+CIPSTART error");
    return;
  }


 // prepare GET string
  String getStr2 = "GET /update?api_key=";
  getStr2 += apiKey;
  getStr2 +="&field2=";
  getStr2 += String(stri);
  getStr2 += "\r\n\r\n";




// send data length
  cmd2 = "AT+CIPSEND=";
  cmd2 += String(getStr2.length());
  ser.println(cmd2);


   if(ser.find(">")){
    ser.print(getStr2);
  }
   else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }



  // thingspeak needs 15 sec delay between updates
  }
     if(millis() - t4>5000)
  {
    t4=millis();
  
   // TCP connection
  String cmd3 = "AT+CIPSTART=\"TCP\",\"";
  cmd3 += "184.106.153.149"; // api.thingspeak.com
  cmd3 += "\",80";
  ser.println(cmd3);

  if(ser.find("Error")){
    //Serial.println("AT+CIPSTART error");
    return;
  }


 // prepare GET string
  String getStr3 = "GET /update?api_key=";
  getStr3 += apiKey;
  getStr3 +="&field3=";
  getStr3 += String(strj);
  getStr3 += "\r\n\r\n";




// send data length
  cmd3 = "AT+CIPSEND=";
  cmd3 += String(getStr3.length());
  ser.println(cmd3);


   if(ser.find(">")){
    ser.print(getStr3);
  }
   else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }

 

  // thingspeak needs 15 sec delay between updates
  }
 

}
double mapf(double val, double in_min, double in_max, double out_min, double out_max) {
    return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
