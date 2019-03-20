#include "ACS712.h"

int aInput = A2;
float vout = 0.0;
float vin = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;
int value = 0;

ACS712 sensor(ACS712_05B, A0);

void setup() {
    pinMode(aInput, INPUT);
    Serial.begin(9600);
    Serial.println("Kalibrasi... Ensure that no current flows through the sensor at this moment");
    int zero = sensor.calibrate();
    Serial.println("Siap untuk mengukur Tegangan dan Arus!");
    Serial.println("Zero point for this sensor = " + zero);
  
}

void loop() {
  // Mengukur Arus
    float I = sensor.getCurrentDC(); // Baca arus dari sensor
    Serial.println(String("I = ") + I + " A"); // Cetak hasil pembacaan sensor 
    delay(500);

  // Mengukur Tegangan
    value = analogRead(aInput);     // Baca tegangan dari sensor
    vout = (value * 5.0) / 1023.0;  // 
    vin = vout / (R2/(R1+R2));
 
    Serial.print("V = ");  // Cetak hasil pembacaan sensor
    Serial.println(vin, 2);
    Serial.print("\n");
    delay(500);
  
}