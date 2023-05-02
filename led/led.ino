#include <LiquidCrystal_I2C.h>

#define led 8
#include <Wire.h>
//button
const int buttonPin = 2;
int buttonState = 0;   
//
const int buzzer = 7;
LiquidCrystal_I2C lcdd(0x27, 16, 2);
int data;
void setup() {
  // put your setup code here,to run once:
  pinMode(buttonPin, INPUT);
  //
  pinMode (8,OUTPUT);
  Serial.begin(9600);

  lcdd.init();
  lcdd.backlight();
  lcdd.println("Bienvenue");

  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
 // read the state of the pushbutton value:
   // initialize the pushbutton pin as an input:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    
  lcdd.init();
  lcdd.backlight();
  lcdd.println("Bienvenue");
  } else if (buttonState == HIGH){
    Serial.println('2');
    Serial.write('2');
    
    lcdd.clear();
    lcdd.setCursor(3, 0);
    lcdd.print("Attention");
    lcdd.setCursor(0, 1);
    lcdd.print(" en panne");
  }
  /////////////////////////
if(Serial.available())
{
  
  data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='1') //si le caractère lu est é-----------------------------------------------------------------------------------------gale à 1-
    {
digitalWrite(led,HIGH);
delay(1000);
digitalWrite(led,LOW);

lcdd.clear();
  lcdd.setCursor(3, 0);
    lcdd.print("Attention");
    lcdd.setCursor(0, 1);String message = Serial.readString(); // Read the message from the serial port
    lcdd.print(message);     

    lcdd.print("EN PANNE");
    for(int i=0;i<10;i++){
      
digitalWrite(led,HIGH);
   digitalWrite(buzzer, HIGH); // turn on the buzzer
  delay(1000); // wait for a second
digitalWrite(led,LOW);
  digitalWrite(buzzer, LOW); // turn off the buzzer
  delay(500); // wait for a second
  }
}
else
{
  lcdd.setCursor(3, 0);
    lcdd.print("                                  ");
    lcdd.setCursor(0, 1);
    lcdd.print("                                   ");
}
}
}
