//Designed By 皎皎
#include <Wire.h>
#include <Arduino.h>
#include "mpu6050.h"
#include "Motor.h"
#include "sr02.h"
#include "mypid.h"

const int MPU_addr=0x68;
extern float Setdistance; 
extern float Actualdistance; 
extern float err; 
float Actualdistance_last;
float a=0.8;
void setup()
{	
	Serial.begin(115200);
	Motor_Init();
	unclock();
	sr02_init();
	PID_init();
	Setdistance=distance_init();
	Actualdistance_last=Setdistance;
	//Wire.begin(21, 22);
	//Wire.beginTransmission(MPU_addr);
	//Wire.write(0x6B); // PWR_MGMT_1 register
	//Wire.write(0); // set to zero (wakes up the MPU-6050)
	//Wire.endTransmission(true);
}
void loop()
{
	Actualdistance=get_distance();
	Actualdistance=a*Actualdistance+(1-a)*Actualdistance_last;
	Serial.print("distance now=\r\n");
	Serial.print(Actualdistance);
	Serial.print("\r\n");
	err=Setdistance-Actualdistance;
	PWM_SetDuty(1250+50*PID_realize(),0);//油门大小816-1640
	Serial.print("pid=\r\n");
	Serial.print(PID_realize());
	Serial.print("\r\n");
	Serial.print(err);
	Serial.print("\r\n");
	Actualdistance_last=Actualdistance;

}

