#include <Wire.h>

unsigned char seconds, minutes, hours, day, date, month, year;
unsigned char RTC=0b1101000;

void setup()
{
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  
  Wire.beginTransmission(RTC);
  
  Wire.write(0);  //Set pointer to seconds' register.
  Wire.write(0b00000000);  //Write 0 to seconds register.
  Wire.write(0b00010000); //Write 10 to the minutes register.
  Wire.write(0b00000011); //Write 3 to the hours register.
  Wire.write(0b00000111); //Write Day
  Wire.write(0b00000101); //Write Date
  Wire.write(0b00000111); //Write Month/Century
  Wire.write(0b00010101); //Write Year
  Wire.write(0b00000000); //Write Seconds Alarm 1
  Wire.write(0b00010010); //Write Minutes Alarm 1
  Wire.write(0b10000011); //Write Hours Alarm 1
  Wire.write(0b10000000); //Write Day Alarm 1
  Wire.write(0b00000000); //Write Date Alarm 1
  Wire.write(0b00000000); //Write Minutes Alarm 2
  Wire.write(0b00000000); //Write Hours Alarm2
  Wire.write(0b00000000); //Write Day Alarms 2
  Wire.write(0b00000000); //Write Date Alarm 2

  Wire.endTransmission();
}

void loop()
{
  Wire.beginTransmission(RTC);
  Wire.write(0);
  Wire.endTransmission();

  Wire.requestFrom(RTC, 3);
  seconds=Wire.read();
  minutes=Wire.read();
  hours=Wire.read();

  seconds=(seconds/16)*10+(seconds%16);
  minutes=(minutes/16)*10+(minutes%16);
  hours=(hours/16)*10+(hours%16);

  Serial.print(hours);
  Serial.print("\t");
  Serial.print(minutes);
  Serial.print("\t");
  Serial.print(seconds);
  Serial.print("\n");
  
}
