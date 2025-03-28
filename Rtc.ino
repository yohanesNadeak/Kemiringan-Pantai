void inRtc() {                               //Fungsi Untuk RTC
  display.clearDisplay();                     //Membersihkan Layar OLED
  display.setTextSize(1);                     //Ukuran Teks pada OLED
  display.setTextColor(SSD1306_WHITE);        //Warna text pada OLED
  display.setCursor(0, 0);                    //Posisi Teks pada OLED
  display.println(F("RTC OKE"));              //Menampilkan init RTC pada OLED
  display.setCursor(40, 40);                    //Posisi Teks pada OLED
  display.println(F("LANJUT!!"));              //Menampilkan init RTC pada OLED
  delay(4000);                                //jeda 3 detik
  display.display();                          //Menampilkan Semua pada OLED
  display.clearDisplay(); 
  display.setCursor(0, 0);                   //Atur posisi teks pada oled
  display.println(F("NAMA KELOMPOK"));    //menampilkan SUHU  
  display.setCursor(0, 20);                   //Atur posisi teks pada oled
  display.println(F("Yosef tampubolon"));    //menampilkan tinggi
  display.setCursor(0, 35);                   //Atur posisi teks pada oled
  display.println(F("Angel debora"));  //menampilkan =
  display.setCursor(0, 50);                   //Atur posisi Teks pada Oled
  display.println(F("Daniel triwandez"));  //menampilkan °C pada oled
  delay(5000);                                //jeda 3 detik
  display.display();                          //Menampilkan Semua pada OLED

  if (!rtc.begin()) {                       //Jika RTC tidak terbaca
    Serial.println("RTC tidak ditemukan");  //Menampilkan RTC tdk ditemukan Pada OLED
    Serial.flush();                         //mengosongkan data yang tersisa di buffer serial.
    display.setCursor(0, 20);               //mengatur posisis teks
    display.println(F("RTC ERROR"));        //Menampilkan RTC eror pada OLED
    display.display();                      //Menampilkan Pada Oled
    while (1) delay(100);                   //Menghentikan oprasi lain (hanya melakukan oprasi pada diri sendiri)
  }
}
void ambilWaktu() {                                  //mengambil waktu dari RTC
  DateTime now = rtc.now() + TimeSpan(0, 0, 0, 20);  //mengambil waktu secara realtime
  sprintf(timeString, "%02d/%02d/%04d %02d:%02d:%02d",  //format tanggal (MM/DD/YYYY HH:MM:SS)
          now.day(), now.month(), now.year(),        // Nilai-nilai yang diambil dari objek datetime (now)
          now.hour(), now.minute(), now.second());   //
  Serial.println(timeString);                           //Menampilkan tanggal pada serial monitor
}
