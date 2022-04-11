#include<Wire.h>
#include <Arduino.h>
#define SDA 21
#define SCL 22

const int MPU_addr=0x68; // I2C address of the MPU-6050
int16_t accX,accY,accZ,Tmp,gyroX,gyroY,gyroZ;
void mpu(void)
{
    Wire.beginTransmission(MPU_addr);
	Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
	Wire.endTransmission(false);
	Wire.requestFrom(MPU_addr,14,true); // request a total of 14 registers
	accX=Wire.read()<<8|Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
	accY=Wire.read()<<8|Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
	accZ=Wire.read()<<8|Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
	Tmp=Wire.read()<<8|Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
	gyroX=Wire.read()<<8|Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
	gyroY=Wire.read()<<8|Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
	gyroZ=Wire.read()<<8|Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
	Serial.print(" | AcX = "); Serial.print(accX);
	Serial.print(" | AcY = "); Serial.print(accY);
	Serial.print(" | AcZ = "); Serial.print(accZ);
	Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53); //equation for temperature in degrees C from datasheet
	Serial.print(" | GyX = "); Serial.print(gyroX);
	Serial.print(" | GyY = "); Serial.print(gyroY);
	Serial.print(" | GyZ = "); Serial.println(gyroZ);
}