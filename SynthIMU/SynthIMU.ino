/*
  Arduino LSM9DS1 - Simple Accelerometer

  This example reads the acceleration values from the LSM9DS1
  sensor and continuously prints them to the Serial Monitor
  or Serial Plotter.

  The circuit:
  - Arduino Nano 33 BLE Sense

  created 10 Jul 2019
  by Riccardo Rizzo

  This example code is in the public domain.
*/

#include <Arduino_LSM9DS1.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

//  Serial.print("Accelerometer sample rate = ");
//  Serial.print(IMU.accelerationSampleRate());
//  Serial.println(" Hz");
//  Serial.println();
//  Serial.println("Acceleration in G's");
  Serial.println("t_mil,AccX,AccY,AccZ,GyroX,GyroY,GyroZ,Magx,Magy,Magz"); // changed this from tab delimiter to comma delimiter in order to get compatability with priting a .csv in Processing
}

void loop() {
  float accx, accy, accz, gyrox, gyroy, gyroz, magx, magy, magz;
    Serial.print(millis());
    Serial.print(',');
  
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(accx, accy, accz);
    
    Serial.print(accx);
    Serial.print(',');// changed this from tab delimiter to comma delimiter
    Serial.print(accy);
    Serial.print(',');// changed this from tab delimiter to comma delimiter
    Serial.print(accz);
    Serial.print(',');
  }
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(gyrox, gyroy, gyroz);
    
    Serial.print(gyrox);
    Serial.print(',');
    Serial.print(gyroy);
    Serial.print(',');
    Serial.print(gyroz);
    Serial.print(',');
  }
  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(magx, magy, magz);

    Serial.print(magx);
    Serial.print(','); //changed from tab delimiter to comma
    Serial.print(magy);
    Serial.print(','); //changed from tab delimiter to comma
    Serial.println(magz);
  }
  else {
    Serial.print("0,");
    Serial.print("0,");
    Serial.println("0");
}
}
