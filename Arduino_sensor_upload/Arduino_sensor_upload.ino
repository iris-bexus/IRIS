/*
 *  Arduino_sensor_upload
 * 
 *  Final program to be uploaded into the Aduino sensor board
 * 
 *  
 *  Created by Edgar Martín Nieto
 * 
 *  Edited by
 * 
 * 
 *  Depends on: SoftI2CMaster.h
 *              Wire.h            
 *              Arduino.h
 *              avr/io.h
 * 
 * v0.1
 */


#define SCL_PORT PORTB
#define SCL_PIN 3
#define SDA_PORT PORTB
#define SDA_PIN 5
#define I2C_NOINTERRUPT 1
#define I2C_FASTMODE 1

#define ADDRESS_ADC_1 0b1001000
#define ADDRESS_ADC_2 0b1001001
#define ADDRESS_ADC_3 0b1001011

#include <SoftI2CMaster.h>
#include <Wire.h>

  // For i2c, R=1, W=0;


  
void setup() {
  Serial.begin(9600);
  i2c_init();    
}

void loop() {

  // Work in progress.

  i2c_start_wait((ADDRESS_ADC_1<<1) | I2C_WRITE);
  while(!i2c_write(0x01));
  while(!i2c_write(0x01));
}
