
#define TRIG 5
#define ECHO 18   

  // Konstanta kecepatan suara (cm)
#define SOUND_SPEED 0.034

void setup() {
 // Inisialisasi serial dengan baudrate 9600
 Serial.begin(9600);

 // Atur mode pin 
 pinMode(TRIG, OUTPUT);
 pinMode(ECHO, INPUT);

 // Pastikan trigger dalam keadaan LOW
 digitalWrite(TRIG, LOW);
 
 Serial.println("HC-SR84 siap membaca jarak...");

}
  
void loop() {
  // Kirim pulsa trigger selama 10 
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

 // Baca durasi pulsa HIGH pada ECHO (timeout 30 ms = 5 meter maks)
  long duration = pulseIn(ECHO, HIGH, 30000);

  // Jika timeout (tidak ada objek dalam jangkauan)
  if (duration == 0) {
   Serial.println("Tidak ada objek (out of range)");
 } else {
  // Hitung jarak dalam cm
  float distance = duration * SOUND_SPEED / 2;

  // Tampilan di Serial Monitor
  Serial.println("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");
  }

  // Tunggu delay
  delay(200);
}
