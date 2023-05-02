#include <Wire.h> // Bibliothèque pour la communication I2C
#include <SPI.h>
#include <Servo.h>
#include <LiquidCrystal.h> // Bibliothèque pour l'afficheur LCD I2C
#include <MFRC522.h> // Bibliothèque pour le module RFID
#include <LiquidCrystal_I2C.h>
#include <AccelStepper.h> // Bibliothèque pour le moteur pas à pas

// Déclaration des broches
#define SS_PIN 10
#define RST_PIN 9
#define LCD_RS A5
#define LCD_EN A4
#define MOTOR_PIN_1 5
#define MOTOR_PIN_2 6
#define MOTOR_PIN_3 7
#define MOTOR_PIN_4 8
#define LED_PIN 4 // La broche pour la LED rouge
// Déclaration des objets
MFRC522 mfrc522(SS_PIN, RST_PIN);
// Initialise l'afficheur LCD
LiquidCrystal_I2C lcd(0x27, 20, 4);
int compteur = 0; // Compteur du nombre de personnes
// Déclaration de l'objet stepper motor
AccelStepper stepper(4, MOTOR_PIN_1, MOTOR_PIN_3, MOTOR_PIN_2, MOTOR_PIN_4);

bool carte_valide = false;
int etat_bouton;
String id ;
void setup() {
  Serial.begin(9600);             // Initialisation de la communication série

  // Initialisation de la communication avec la carte RFID
  SPI.begin();
  mfrc522.PCD_Init();

  // Initialise l'afficheur LCD
  lcd.init();
  lcd.backlight();
  // Définir la vitesse et l'accélération du moteur pas à pas
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  // Initialisation de la LED rouge
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Eteindre la LED rouge
  // Affiche le message "Bienvenue" sur l'afficheur LCD
  lcd.setCursor(0, 0);
  lcd.print("Bienvenue");
   

}

void loop() {

       Serial.write("0");
  if(Serial.available()){

     lcd.clear();  // Efface l'écran LCD
      lcd.setCursor(1,0); 
     lcd.print( "conference :");
      delay(2000);
      lcd.clear(); 
      lcd.setCursor(2,1);  // Place le curseur en haut à gauche de l'écran LCD
     lcd.print( Serial.readString());
    delay(2000);

  // Vérification de la présence d'une carte RFID
  if (mfrc522.PICC_IsNewCardPresent() )
   {  
    lcd.clear();  // Efface l'écran LCD
    lcd.setCursor(2,0);
    lcd.print("carte_detecte");
    delay(2000);
   id="";
if( mfrc522.PICC_ReadCardSerial()) 
    {  
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      id += String(mfrc522.uid.uidByte[i], HEX);
    }
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  
 

}
    // Vérification si l'identifiant de la carte est valide
    if (id == "e3e69c92") {
    Serial.write("1");
  compteur++;
    lcd.clear();  // Efface l'écran LCD
    lcd.setCursor(3,1);  // Place le curseur en haut à gauche de l'écran LCD
    lcd.print("Acces autoriser ");
     delay(2000);
    lcd.clear();  // Efface l'écran LCD
     lcd.setCursor(3,1);  
     lcd.print("nom de la personne :" );
     delay(2000);
  
     lcd.clear();  // Efface l'écran LCD
     lcd.setCursor(3,1);  
     lcd.print(Serial.readString());
     delay(2000);
     
     lcd.clear();  // Efface l'écran LCD
     lcd.setCursor(3,0);
     lcd.print("nombre personne:");
     delay(2000);
     Serial.write(compteur);
    lcd.clear();  // Efface l'écran LCD
    lcd.setCursor(1,1);
    lcd.print(compteur);
    delay(2000);
  // Tourner le moteur pas à pas
  stepper.moveTo(5000);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
    delay(1);
  }
   } 
  else 
  {
   // Accès refusé
  digitalWrite(4, HIGH); // Allumer la LED rouge
    lcd.clear();  // Efface l'écran LCD
    lcd.setCursor(1,1);  // Place le curseur en haut à gauche de l'écran LCD
    lcd.print("Acces non autoriser:");
      delay(2000);
  digitalWrite(4, LOW); // Éteindre la LED rouge

    
  }
  }
  if(Serial.readString()=="1")
  
 {
     lcd.clear();  // Efface l'écran LCD
    lcd.setCursor(1,1);  // Place le curseur en haut à gauche de l'écran LCD
    lcd.print(" a bientot ");
      delay(2000);
        // Tourner le moteur pas à pas
  stepper.moveTo(5000);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
    delay(1);
  }
       
 } if(Serial.readString()=="2")
  
 {
     lcd.clear();  // Efface l'écran LCD
    lcd.setCursor(1,1);  // Place le curseur en haut à gauche de l'écran LCD
    lcd.print(" arret du programe! ");
      delay(2000);
// Arrêt de la communication avec la carte RFID
mfrc522.PICC_HaltA();
mfrc522.PCD_StopCrypto1();
exit(0); // Arrêt du programme
  }}
  /*else if(Serial.readString()=="3")
   {
    void (*resetFunc)(void) = 0; // Declare reset function at address 0
     lcd.clear();  // Efface l'écran LCD
    lcd.setCursor(1,1);  // Place le curseur en haut à gauche de l'écran LCD
    lcd.print(" Bienvenue ");
     delay(2000);
// Arrêt de la communication avec la carte RFID
mfrc522.PICC_HaltA();
mfrc522.PCD_StopCrypto1();

  }*/
}
    

  


   
