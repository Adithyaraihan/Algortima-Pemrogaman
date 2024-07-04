#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9; 
const int echoPin = 10;
long durasi; // Variabel untuk menyimpan waktu perubahan PIN Echo dari LOW ke HIGH
int jarak; 

void setup() {
  pinMode(trigPin, OUTPUT); // Output untuk mengirimkan gelombang suara ultrasonic
  pinMode(echoPin, INPUT); // Input untuk menerima pantulan gelombang suara ultrasonic
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Alat pengukur ");
  lcd.setCursor(0, 1);
  lcd.print("Adithya Raihan");
  delay(2000);
  Serial.begin(9600); //setup serial monitor dan kecepatan komunikasi
}

void loop() {
  // Membersihkan trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Membuat nilai trigPin menjadi HIGH
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); ==
  digitalWrite(trigPin, LOW);

  // Membaca echoPin dan memberikan waktu perjalanan gelombang dalam mikro detik\ 
  durasi = pulseIn(echoPin, HIGH);

  // Menghitung jarak tempuh gelombang suara
  jarak = (durasi*0.034/2)+1;

  Serial.print("Jarak: ");
  Serial.println(jarak);

  //monitor 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mengukur jarak");
  lcd.setCursor(0, 1);
  lcd.print("Jarak : ");
  lcd.setCursor(7, 1);
  lcd.print(jarak);
  lcd.setCursor(10, 1);
  lcd.print(" Cm");
  delay(500);
}
