void sensorAir() {

  // Baca nilai dari sensor level air

 digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // Mengukur durasi pulsa
  distance = duration * 0.034 / 2;   // Menghitung jarak berdasarkan durasi

 if (isnan(duration) || isnan(distance)) {
    Serial.println("sensor gagal!");  //satu dari pembacaan gagal maka akan mencetak di serial monitor
  } else {
    Serial.print("Jarak: ");  //Menampilkan pada serial monitor
    Serial.print(distance);                 //Menampilkan nilai dari tinggi
    Serial.println("Cm");

  }
}