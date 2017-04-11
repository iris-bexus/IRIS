#define SCL_PORT PORTC
#define SCL_PIN 5
#define SDA_PORT PORTC
#define SDA_PIN 5
#define I2C_NOINTERRUPT 1
#define I2C_FASTMODE 1

#include <SoftI2CMaster.h>
#include <Wire.h>

#define RTC 0b11010000
#define Memory 0b10101110

  //unsigned char seconds, minutes, hours, day, date, month, year, a1seconds, a1minutes, a1hours, a1daydate, a2minutes, a2hours, a2daydate, control, status, offset, temp1, temp2;
  unsigned char CurrentAddress=0;


  // For i2c, R=1, W=0;
  
void setup() {
  Serial.begin(9600);
  i2c_init();
}

void loop() {

  i2c_start_wait(Memory | I2C_WRITE);
  while(!i2c_write(0x00));
  while(!i2c_write(0x01));
  
  
  Serial.print(CurrentAddress);
  Serial.print("\n");
  delay(1000);
}
