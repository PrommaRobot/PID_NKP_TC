#include <popx2.h>
#include "NKP_TCSensor.h"


uint8_t numSensor = 4;
float Kp = 0.65  ;
float Ki = 0;
float Kd = 5;

// การปรับ PID นั้น เริ่มจากการปรับที่ KP ก่อน แล้วให้ KI KD ตัวอื่น ๆให้เป็น 0 ให้หมด
// เมื่อหุ่นยนต์ของเรา วิ่งกลับมาจุดกลึงกลางแล้วก็ปรับ KD เพิ่มมากชึ้นทำให้การสวิงนั้นต่ำลง
// พร้อมกับลดค่า KP ลงเพิ่มเติม
// ทำไมถึงไม่พูดถึง KI ก็เพราะว่า ตามหลักแล้ว KI ที่จะใช้คือน้อยมาก ๆเลย ผมเลยไม่ขอยกขึ้นมานะครับ
// หรือถ้าปรับ KI ไม่ดีจะทำให้เกิดการ ทำให้ระบบมันระเบิด เอาภาษาง่าย ๆแล้วมันก็จะไม่จับเส้ยนะจ่ะ
uint16_t setpoint;
float present_position;
float errors = 0;
float output = 0;
float integral ;
float derivative ;
float previous_error ;

void pid(float Kp, float Kd, int sp){
  int Ki=0;
  int speed_max = sp;
  present_position = readline() /( (numSensor - 1) * 10 );
  setpoint = 50;
  errors = setpoint - present_position;
  integral = integral + errors ;
  derivative = (errors - previous_error) ;
  output = Kp * errors + Ki * integral + Kd * derivative;
  previous_error = errors;
  if(output > 100 )output = 100;
  else if(output < -100)output = -100;
  motor(1, speed_max - output);
  motor(2, speed_max + output);
  delay(1);
  
  }

void pid_t(float Kp,float Kd, int sp,int t){
  long a = millis();
  while(millis() < t+a){
    pid(Kp,Kd,sp);
  }
}

void square(int num){
  int x = 0;
  while(1){
    if(num==0)  break;
    else{
      if( analog(0)<500&&analog(1)<500 ){
        fd(20); delay(100);
        ao(); num -= 1; x=0;
        while(analog(4)>500)  sl(30);
        
      }
      else if( analog(4)<500&&analog(5)<500 ){
         fd(20); delay(100);
        ao(); num -= 1; x=0;
        while(analog(1)>500)  sr(30);

      }
      else if(analog(1)>500&&analog(4)<500){
        motor(1,40);
        motor(2,10);
      }
      else if(analog(1)<500&&analog(4)>500){
        motor(1,10);
        motor(2,40);
      }
      else{
        motor(1,20+x);
        motor(2,20+x);
      }
      x+=3;
      if(x>20) x=20;
    }
  }
}

void square2(int num){
  int x = 0;
  while(1){
    if(num==0)  break;
    else{
      if( analog(4)<500&&analog(1)<500 ){
        fd(20); delay(100);
        ao(); num -= 1; x=0;
        
      }
      else if(analog(1)>500&&analog(4)<500){
        motor(1,40);
        motor(2,10);
      }
      else if(analog(1)<500&&analog(4)>500){
        motor(1,10);
        motor(2,40);
      }
      else{
        motor(1,20+x);
        motor(2,20+x);
      }
      x+=3;
      if(x>20) x=20;
    }
  }
}

void setup() {
  OK();
  setSensorPins((const int[]) {25, 26, 27 , 28}, 4);
  //setSensorMax((const int[]) {1, 2, 3, 4});
  //setSensorMin((const int[]) {5, 6, 7, 8});
  for(int i = 0;i<5000;i++){
    setCalibrate();
    }
  beep();
  delay(1000);
  OK();
  pid_t(1,0,40,4000);
  pid_t(1,0,30,100);
  square(6);
  square2(1);
  square(1);
  
  ao();
  

}

void loop() {
  
  //Serial.print("  readline");  
  //Serial.println(readline());

}
