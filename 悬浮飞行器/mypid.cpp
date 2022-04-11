//Designed By 皎皎
#include <Arduino.h>
#include<cmath>
#include "sr02.h"
#include "mypid.h"


    float Setdistance;            //定义设定值
    float Actualdistance;        //定义实际值
    float err;                //定义偏差值
    float err_last;            //定义上一个偏差值
    float Kp,Ki,Kd;            //定义比例、积分、微分系数
    float voltage;            //定义电压值（控制执行器的变量）
    float integral;            //定义积分值
    float umax;
    float umin;
    int jifen;

void PID_init(){
    Serial.print("PID_init begin \n");
    Setdistance=0.0;
    Actualdistance=0.0;
    err=0.0;
    err_last=0.0;
    voltage=0.0;
    integral=0.0;
    Kp=0.2;
    Ki=0.1;       //注意，和上几次相比，这里加大了积分环节的值
    Kd=0.1;
    umax=100;
    umin=-100;
    Serial.print("PID_init end \n");
}
float PID_realize(void){
    int index;

   if(Actualdistance>umax)  //灰色底色表示抗积分饱和的实现
    {

       if(abs(err)>200)      //蓝色标注为积分分离过程
        {
            index=0;
        }else{
            index=1;
            if(err<0)
            {
    integral+=err;
            }
        }
    }else if(Actualdistance<umin){
        if(abs(err)>200)      //积分分离过程
        {
            index=0;
        }else{
            index=1;
            if(err>0)
            {
            integral+=err;
            }
        }
    }else{
        if(abs(err)>200)                    //积分分离过程
        {
            index=0;
        }else{
            index=1;
            integral+=err;
        }
    }
    jifen=integral;
    jifen%=200;
    voltage=Kp*err+0*index*Ki*jifen+Kd*(err-err_last);

    err_last=err;
    Actualdistance=voltage*1.0;
    return Actualdistance;
}