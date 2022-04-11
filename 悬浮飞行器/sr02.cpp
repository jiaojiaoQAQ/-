//Designed By 皎皎
#include <Arduino.h>
float distance2;
float distance3;
const int echo=3;
const int trig=2;
void sr02_init(void)
{
pinMode(echo,INPUT);
pinMode(trig,OUTPUT);
}
float distance_init(void)
{
    digitalWrite(trig,LOW);
    delayMicroseconds(20);
    digitalWrite(trig,HIGH);
    delayMicroseconds(20);
    digitalWrite(trig,LOW);

    distance2=pulseIn(echo,HIGH);
    distance2=distance2*340/2/10000;
    Serial.print("距离=");
    Serial.print(distance2);
    Serial.println("cm");
    return distance2;
}
float get_distance()
{
    digitalWrite(trig,LOW);
    delayMicroseconds(20);
    digitalWrite(trig,HIGH);
    delayMicroseconds(20);
    digitalWrite(trig,LOW);

    distance3=pulseIn(echo,HIGH);
    distance3=distance3*340/2/10000;
    //Serial.print("距离=");
    //Serial.print(distance3);
    //Serial.println("cm");
    return distance3;
}