void inMicroSD() {
  while (!Serial) {  //Tunggu hingga koneksi Serial Monitor
    ;
  }
  Serial.print("Initializing SD card...");  //Mencetak pesan ke Serial Monitor
  if (!SD.begin(5)) {                       //Mencoba menginisialisasi kartu SD pada pin 5
    display.clearDisplay();
    display.setCursor(20, 50);
    display.print("sd card error!");
    display.display();  //Jika inisialisasi gagal, cetak pesan kesalahan
    while (1)
      ;  //Masuk ke loop tak terhingga untuk menghentikan eksekusi program
  }
  Serial.println("initialization done.");  //Jika inisialisasi berhasil, cetak pesan bahwa inisialisasi selesai

  display.clearDisplay();               //Membersihkan Layar OLED
  display.setTextSize(1);               //Ukuran Teks pada OLED
  display.setTextColor(SSD1306_WHITE);  //Warna text pada OLED
  display.setCursor(0, 0);              //Posisi Teks pada OLED
  display.println(F("MICRO SD AMAN"));  //Menampilkan Micro sd aman pada OLED
  display.setCursor(40, 40);              //Posisi Teks pada OLED
  display.println(F("GAASS KEUNN!!"));
  delay(2000);
  display.display();  //Menampilkan pada oled
}

void simpanDatawaktu() {
  //nama dari microSD
  myFile = SD.open("/dloger.txt", FILE_APPEND);  //(tidak akan menimpa file yang sudah ada)
  if (myFile) {
    // Baca nilai dari sensor level air
   digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

    DateTime now = rtc.now() + TimeSpan(0, 0, 0, 20);  //mengambil waktu secara realtime
    sprintf(timeString, "%02d/%02d/%04d %02d:%02d:%02d",  //format tanggal (MM/DD/YYYY HH:MM:SS)
            now.day(), now.month(), now.year(),        // Nilai-nilai yang diambil dari objek datetime (now)
            now.hour(), now.minute(), now.second());
    myFile.print(timeString);           //simpan tanggal yang sudah di set ke dalam micro sd
    myFile.print(", Jarak: ");  //simpan suhu ke dalam micro sd
    myFile.print(distance);         //simpan nilai suhu yang sudah di dapatkan ke dalam micro sd
    myFile.println(" cm");
    myFile.close();                  // Mengakhiri proses penulisan ke file kartu SD
  } else {
    // if the file didn't open, print an error:
    Serial.println("gagal membuka dloger.txt");  //jika microsd gagal maka akan menampilkan
  }
}
