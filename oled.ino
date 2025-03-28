//Memulai Komunikasi Pada Oled
void inOled() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {  //mencoba Komunikasi oled dan alamat I2C
    Serial.println(F("SSD1306 allocation failed"));            //Jika inisiasi gagal maka akan menampilkan
    for (;;)                                                   //tidak akan berlanjut lagi(oled terjebak disini)
      ;
  }
  display.clearDisplay();  //membersihkan oled
  delay(1000);             //jeda selama 1 detik
}

void tampilWaktu() {
  DateTime now = rtc.now() + TimeSpan(0, 0, 0, 20);     // Ambil waktu saat ini dari RTC
  display.fillRect(0, 0, 128, 10, BLACK);               //Membuat garis atas layar kosong,koordinat x=0, y=0 hingga lebar 128 pixel dan tinggi 10 pixel
  display.setTextSize(1);                               //Ukuran Teks pada oled
  display.setTextColor(SSD1306_WHITE);                  //mengatur warna teks
  sprintf(timeString, "%02d/%02d/%04d %02d:%02d:%02d",  //format tanggal (MM/DD/YYYY HH:MM:SS)
          now.day(), now.month(), now.year(),           // Nilai-nilai yang diambil dari objek datetime (now)
          now.hour(), now.minute(), now.second());      //
  display.setCursor(0, 0);                              // Atur posisi kursor text pada oled
  display.println(timeString);                          //menampilkan tanggal pada oled
  display.display();                                    // Tampilkan semua di layar
}

void tampilkantinggi() {
 digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // Mengukur durasi pulsa
  distance = duration * 0.034 / 2;   // Menghitung jarak berdasarkan durasi
 
  display.fillRect(75, 20, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);  //Membuat garis atas layar kosong
  display.setTextSize(1);                                        //Mengatur Posisi text
  display.setTextColor(WHITE);                                   //Mengatur warna text
  display.setCursor(75, 20);                                     //Atur posisi teks pada oled
  display.println(distance);                                    //menampilkan tinggi
  display.setCursor(110, 20);                                    //Atur posisi Teks pada Oled
  display.println(F("Cm"));                                       //menampilkan %
  display.display();                                             //Tampilkan semuanya
}

void logo() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);       //Menginisialisasi layar OLED
  display.clearDisplay();                          //Membersihkan tampilan oled
  display.drawBitmap(0, 0, myBitmap, 128, 64, 1);  //Menggambar bitmap dengan posisi ditengah
  display.display();                               //Menampilkan semua pada oled
  delay(3000);                                     //jeda selama 3detik
  display.clearDisplay();                          //Membersihkan layar pada oled
  display.setTextSize(2);                          //ukuran text pada oled
  display.setTextColor(SSD1306_WHITE);             //Mengatur warna pada teks
  display.setCursor(20, 40);                         //atur posisi pada oled
  display.println(F("SENTINELS"));                //tampilkan
  display.display();  //Menampilkan semua pada oled
  delay(2000);        //jeda selama 3detik                                                 //jeda selama 2 detik
  display.clearDisplay();
  display.setTextSize(2);               //ukuran text pada oled
  display.setTextColor(SSD1306_WHITE);  //Mengatur warna pada teks
  display.setCursor(0, 0);              //atur posisi pada oled
  display.println(F("DATA LOGER"));
  display.setCursor(40, 25);                        //atur posisi pada oled
  display.println(F("Water "));
  display.setCursor(40, 50);                        //atur posisi pada oled
  display.println(F("level"));
  display.display();  //Menampilkan semua pada oled
  delay(2000);
}