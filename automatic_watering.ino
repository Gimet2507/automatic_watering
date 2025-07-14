//Penyiram tanaman otomatis

#define BLYNK_PRINT Serial 
#define BLYNK_TEMPLATE_ID "TMPL6XbHTFEvI"
#define BLYNK_TEMPLATE_NAME "penyiraman IOT"
#define BLYNK_AUTH_TOKEN "FCU0tagq_AqAJPBHGvI0G5ggcEflydmH"   
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

char auth[] = "FCU0tagq_AqAJPBHGvI0G5ggcEflydmH"; //ISI TOKEN PADA APLIKASI BLYNX ANDROID
char ssid[] = "tenda";                             //NAMA HOTSPOT 
char pass[] = "duakelinci";                         //password hotspot



const int sensorTanah = A0; //inisialisasi pin sensor
const int relay = D3;       //inisialisasi pin relay 


void setup() {
Serial.begin (9600);          //memanggil serial monitor
pinMode(sensorTanah, INPUT);   //menetapkan sensor tanah atau pin A0 sebagai input
pinMode(relay, OUTPUT);       //menetapkan relay atau pin D6 sebagai output
Blynk.begin(auth, ssid, pass);


}

void loop() {
int dataAnalog = analogRead (sensorTanah);  //membaca nilai dari pin sensor
//print hasil ke serial monitor
Serial.print ("A0 : ");
Serial.print (dataAnalog);
//print hasil ke blink 
Blynk.virtualWrite(V1, "NILAI SENSOR");
Blynk.virtualWrite(V0, dataAnalog);
Blynk.run();

//jika nilai A0 lebih dari 600, relay menyala, print ke serial monitor dan ke lcd
if (dataAnalog > 600) { 
  Serial.println(". Tanah Kering"); 
  {
  digitalWrite (relay, HIGH);
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("TANAH KERING");
  lcd.setCursor(0,1);
  lcd.print("NILAI SENSOR:");
  lcd.print (dataAnalog);
  
   
}
  
  
  }

 //tetapi, jika nilai A0 kurang dari 350, relay mati, print ke serial monitor dan lcd
 else if (dataAnalog  < 350) {
  Serial.println(". Tanah Masih Basah"); 
   {
  digitalWrite (relay, LOW);
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("TANAH BASAH");
  lcd.setCursor(0,1);
  lcd.print("NILAI SENSOR:");
  lcd.print (dataAnalog);
  
   
}
  
  
  }
//juga tetapi, jika nilai A0 kurang dari 550 dan lebih dari 350, relai mati, print ke serial monitor dan lcd
 else if (dataAnalog  < 550) {
  Serial.println(". Kelembaban Tanah Normal"); 
   {
  digitalWrite (relay, HIGH);
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("TANAH NORMAL");
  lcd.setCursor(0,1);
  lcd.print("NILAI SENSOR:");
  lcd.print (dataAnalog);
  }
}
 delay (500);
}
