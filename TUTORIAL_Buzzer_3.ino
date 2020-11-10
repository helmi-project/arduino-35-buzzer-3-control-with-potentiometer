/*
   TUTORIAL PASSIVE BUZZER PADA ARDUINO
   GABUNG POTENSIO DAN SEVEN SEGMENT
   D3 -> Passive Buzzer +

   Potensio -> A0
   CLK -> D10
   DIO -> D11

*/
#include <Arduino.h>
#include <TM1637Display.h>

#define pinBuzzer 3 //buzzer pada pin D3
#define PIN_POTENSIO A0
#define CLK 10
#define DIO 11
int jeda = 200;
TM1637Display display(CLK, DIO);

void setup() {
  pinMode(pinBuzzer, OUTPUT); //set menjadi output
  pinMode(PIN_POTENSIO, INPUT); //set A0 menjadi input (potensio)
  display.setBrightness(0x0f);
}

void loop() {
  int nilaiPotensio = analogRead(PIN_POTENSIO);
  int frek = map(nilaiPotensio, 0, 1023, 251, 1046); //memetakan nilai analog potensio 0-1023 ke nilai rentang frekwensi
  playTone(frek, 300); //nada C
  display.showNumberDec(frek, false);
  delay(jeda); //jeda waktu 1 detik, akan tetap menyala selama 1 detik

}


void playTone(long note, long millisecond) {
  long frequency = note;
  long length = millisecond;
  if (frequency > 0) {
    long delayValue = 1000000 / frequency / 2; 
    long numCycles = frequency * length / 1000; 
    for (long i = 0; i < numCycles; i++) { 
      digitalWrite(pinBuzzer, HIGH); 
      delayMicroseconds(delayValue); 
      digitalWrite(pinBuzzer, LOW); 
      delayMicroseconds(delayValue); 
    }
  }
  else delay(millisecond);
}
