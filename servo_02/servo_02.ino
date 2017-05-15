#include <Servo.h> 
Servo myservo;  //创建一个舵机控制对象
                          // 使用Servo类最多可以控制8个舵机
int pos = 0;    // 该变量用与存储舵机角度位置
/*~~~~~~~~~~~~~~~~~~~~~~~~~~华丽的分割线~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void setup() 
{ 
  myservo.attach(10);  // 该舵机由arduino第九脚控制
  
} 
/*~~~~~~~~~~~~~~~~~~~~~~~~~~华丽的分割线 ~~~~~~~~~~~~~~~~~~~~~~~~~~ */ 
void loop() 
{ 
 myservo.write(90);
 delay(1500);
 myservo.write(0);
 delay(1500);
}

