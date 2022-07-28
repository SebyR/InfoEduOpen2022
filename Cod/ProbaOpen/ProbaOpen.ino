#include <Servo.h>
    
Servo baza;  // create servo object to control a servo
Servo s1;
Servo s2;
Servo s3;


// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int bazataux,servaux1,servaux2,servaux3;

void setup() {
  Serial.begin(9600);
  

  
  baza.attach(3);  // attaches the servo on pin 9 to the servo object
  s1.attach(4);
  s2.attach(5);
  s3.attach(6);
     baza.write(90);
   delay(100);
   s1.write(90);
   delay(100);
   s2.write(90);
   delay(100);
   s3.write(90);
}


void loop() {
  String com = Serial.readStringUntil('\n');
  if (com.indexOf("b") != -1){
    String bz = com.substring(com.indexOf("b ")+2);
     int bazat = bz.toInt();
    Serial.println(bazat);
    baza.write(bazat);
  }
    if (com.indexOf("s1 ") != -1){
    String sv1 = com.substring(com.indexOf("s1 ")+3);
     int serv1 = sv1.toInt();
     if (serv1 >= 180){
      serv1 = 180;
     }
     if (serv1 <= 30){
      serv1 = 30;
     }
    Serial.println(serv1);
    s1.write(serv1);
  }
    if (com.indexOf("s2 ") != -1){
    String sv2 = com.substring(com.indexOf("s2 ")+3);
     int serv2 = sv2.toInt();
     if(serv2 <= 0){
      serv2 = 0;
     }
     if(serv2 >=165){
      serv2 = 165;
     }
    Serial.println(serv2);
    s2.write(serv2);
  }
  if (com.indexOf("s3 ") != -1){
    String sv3 = com.substring(com.indexOf("s3 ")+3);
     int serv3 = sv3.toInt();
         if(serv3 <= 60){
      serv3 = 60;
     }
     if(serv3 >=160){
      serv3 = 160;
     }     
    Serial.println(serv3);
    s3.write(serv3);
  }
}
