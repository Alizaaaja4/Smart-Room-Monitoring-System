#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define Kualitas_Udara 400  // Ambang batas kualitas udara
#define Batas_Suhu 30       // Ambang batas suhu
#define Batas_Cahaya 400 // Ambang batas cahaya

// Definisikan pin sensor dan LCD
#define DHTPIN 2           // Pin untuk sensor DHT
#define DHTTYPE DHT22      // Pilih DHT22
#define MQ_PIN A0          // Pin untuk sensor MQ-2 (analog)
#define LDR_PIN A2         // Pin untuk LDR (analog)
#define LED_PIN 13         // Pin untuk LED indikator cahaya
#define BUZZER_PIN 12      // Pin untuk Buzzer

// Inisialisasi objek sensor
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 20, 4); // LCD 20 x 4 dengan alamat I2C 0x27

void setup() {
  // Mulai komunikasi serial dan LCD
  Serial.begin(9600);
  dht.begin();         // Inisialisasi sensor DHT
  lcd.begin(20, 4);    // Inisialisasi LCD 20x4
  lcd.backlight();     // Aktifkan lampu latar LCD

  pinMode(LED_PIN, OUTPUT); // set sebagai output sensor cahaya
  pinMode(BUZZER_PIN, OUTPUT); // set sebagai output sensor api

  lcd.setCursor(0, 0);
  lcd.print("Inisialisasi...");
  delay(2000); // Tunggu beberapa detik untuk inisialisasi
  lcd.clear();
}

void loop() {
  // Membaca suhu dan kelembapan dari sensor DHT
  float suhu = dht.readTemperature();    // Baca suhu dalam Celcius
  float kelembapan = dht.readHumidity(); // Baca kelembapan

  // Membaca nilai dari sensor MQ-2 (asap)
  int nilaiAsap = analogRead(MQ_PIN);  // Baca nilai dari sensor asap

  // Membaca nilai dari LDR (sensor cahaya)
  int nilaiCahaya = analogRead(LDR_PIN); // Baca nilai cahaya

  // Cek apakah pembacaan sensor gagal
  if (isnan(suhu) || isnan(kelembapan)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Gagal membaca sensor!");
    return;
  }

  // Tampilkan data suhu dan kelembapan pada LCD
  lcd.setCursor(0, 0);
  lcd.print("Suhu: " + String(suhu) + " C");
  lcd.setCursor(0, 1);
  lcd.print("Kelembapan: " + String(kelembapan) + "%");

  // Cek apakah suhu melebihi batas yang ditentukan
  // if (suhu > Batas_Suhu) {
  //   lcd.setCursor(0, 2);
  //   lcd.print("Suhu terlalu tinggi!");
  // } else {
  //   lcd.setCursor(0, 2);
  //   lcd.print("Suhu normal.     ");
  // }

  // Cek sensor LDR (deteksi cahaya)
  if (nilaiCahaya < Batas_Cahaya) {
    digitalWrite(LED_PIN, HIGH);
    lcd.setCursor(0, 2);
    lcd.print("Cahaya rendah!   ");
  } else {
    digitalWrite(LED_PIN, LOW);
    lcd.setCursor(0, 2);
    lcd.print("Cahaya cukup.    ");
  }

  // Cek sensor MQ-2 (deteksi asap) dan periksa ambang kualitas udara
  if (nilaiAsap > Kualitas_Udara) {
    digitalWrite(BUZZER_PIN, HIGH);
    lcd.setCursor(0, 3);
    lcd.print("Peringatan: Asap!");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    lcd.setCursor(0, 3);
    lcd.print("Suhu normal");
  }

  delay(3000);  // Tunggu 2 detik sebelum pembacaan berikutnya
  lcd.clear();
}
