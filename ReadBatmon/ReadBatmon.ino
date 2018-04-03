
#include <Wire.h>
#include "Batmon.h"

// Include the required Wire library for I2C<br>#include 
int x = 0;
uint8_t i2cAddress = 0x21;
Batmon bm(i2cAddress ,0);
Therms ts;
#define num
void setup() {
  // Start the I2C Bus as Master
  Serial.begin(115200);
  Serial.println("Read Batmon");
  Wire.setClock(100000);
}
void loop() {

  Wire.beginTransmission(i2cAddress);
  Wire.write(0x11);
  Wire.endTransmission(false);
  uint8_t numB= 10, actNum;
  actNum = Wire.requestFrom(i2cAddress, numB);
  Serial.print(actNum);
  Serial.print(" -- ");
  for (int i =0;i<10;i++)
  {
    Serial.print((unsigned char)Wire.read()); 
    Serial.print("  ");
  }
  Serial.println();
  /*
  Serial.println("Read Batmon 1");
  byte a = bm.readTherms(ts);
  Serial.print(a);
  Serial.print( " ---- ");
//  Serial.println(ts.T2Byte.T2_HI);
//  Serial.println(ts.T2Byte.T2_LO);
  Serial.print(ts.T2.T2Byte.T2_HI);
  Serial.print( " ---- ");
  Serial.println(ts.T2.T2Byte.T2_LO);  
  */
  delay(200);
}

