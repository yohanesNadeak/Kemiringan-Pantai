#include <SD.h>                //Library Micro SD  
#include <FS.h>                //Library Micro SD
#include <Wire.h>              //Library komunikasi I2C
#include "RTClib.h"            //library RTC
#include "variabel.h"          //Variabel data tanggal dan logo
#include <Adafruit_GFX.h>      //Library mengelolah tampilan Oled
#include <Adafruit_SSD1306.h>  //Library mengelolah tampilan Oled

#define SCREEN_WIDTH 128                                                   //Panjang Oled
#define SCREEN_HEIGHT 64                                                   //Lebar Oled
#define OLED_RESET -1                                                      //pin reset untuk layar OLED
#define trigPin 34 // Trigger menggunakan pin 34
#define echoPin 27 // Echo menggunakan pin 27
#define SCREEN_ADDRESS 0x3C                                                //Alamat komunikasi I2C
#define LOGO_HEIGHT 128                                                    //Ukuran panjang logo pada oled
#define LOGO_WIDTH 64                                                      //Ukuran Lebar logo pada oled
RTC_DS3231 rtc;                                                            //Objek RTC
File myFile;                                                               //Objek MICRO SD
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);  // mendefinisikan dimensi layar OLED (128x64 piksel)
unsigned long previousSaveMillis = 0; // Waktu penyimpanan terakhir
const long saveInterval = 5000;       // Interval penyimpanan data (5 detik)

long duration; // Variabel untuk menyimpan durasi pulsa
float distance; // Variabel untuk menyimpan jarak


void setup() {
  Serial.begin(115200);  //Memulai komunikasi Serial
    pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  inOled();             //Menghubungkan ke oled
  logo();                //Menampilkan Logo pada oled
  inMicroSD();          //Menghubungkan Ke MicroSD
  inRtc();              //Menghubungkan ke RTC
  delay(1000);

  display.clearDisplay();               //Bersihkan Layar Oled
  display.setTextSize(1);               //Ukuran teks Pada Oled
  display.setTextColor(SSD1306_WHITE);  //Warna Pada Teks Oled

  ambilWaktu();                //Mengambil waktu
  tampilWaktu();               //Menampilkan waktu
  display.setCursor(0, 20);    //Atur posisi teks pada oled
  display.println(F("Jarak"));  //menampilkan tinggi
  display.setCursor(65, 20);   //Atur posisi teks pada oled
  display.println(F("="));     //menampilkan =

  display.display();            //Tampilkan semuanya
}

void loop() {
  simpanDatawaktu();
  sensorAir();    //Membaca sensor air
  tampilWaktu();  //Menampilkan waktu
  tampilkantinggi();
  delay(800);  //jeda 0,2 detik
}