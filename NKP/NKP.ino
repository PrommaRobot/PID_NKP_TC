#include <NKP_ONE.h>


uint16_t state_on_Line = 0;

uint8_t numSensor = 8;
int numm = (int)numSensor;
int avg[8];
void Run_fast(int delay_timer) {
  float Kp = 4 ;
  float Ki = 0;
  float Kd = 50;
  uint16_t setpoint;
  float present_position;
  float errors = 0;
  float output = 0;
  float integral ;
  float derivative ;
  float previous_error ;
  long timer =0;
  timer = millis();
  do {
    int speed_max = 85;
    present_position = readline() / ((numSensor - 1) * 10) ;
    setpoint = 50.0;
    errors = setpoint - present_position;
    integral = integral + errors ;
    derivative = (errors - previous_error) ;
    output = Kp * errors + Ki * integral + Kd * derivative;
    int max_output = 100;
    previous_error = errors;
    if (output > max_output )output = max_output;
    else if (output < -max_output)output = -max_output;
    motor(1, speed_max - output);
    motor(2, speed_max + output);
    delay(1);

  } while ((millis() - timer) < delay_timer);
}
void Run_slow(int delay_timer,float Kp,float Ki,float Kd) {
  
  uint16_t setpoint;
  float present_position;
  float errors = 0;
  float output = 0;
  float integral ;
  float derivative ;
  float previous_error ;
  long timer = millis();
  do {
    int speed_max = 40;
    present_position = readline() / ((numSensor - 1) * 10) ;
    setpoint = 50.0;
    errors = setpoint - present_position;
    integral = integral + errors ;
    derivative = (errors - previous_error) ;
    output = Kp * errors + Ki * integral + Kd * derivative;
    int max_output = 100;
    previous_error = errors;
    if (output > max_output )output = max_output;
    else if (output < -max_output)output = -max_output;
    motor(1, speed_max - output);
    motor(2, speed_max + output);
    delay(1);
    
  } while (millis() - timer < delay_timer  );
}
void Run_slow2(int delay_timer,float Kp,float Ki,float Kd,int speed_max) {
  
  uint16_t setpoint;
  float present_position;
  float errors = 0;
  float output = 0;
  float integral ;
  float derivative ;
  float previous_error ;
  long timer = millis();
  do {
    present_position = readline() / ((numSensor - 1) * 10) ;
    setpoint = 50.0;
    errors = setpoint - present_position;
    integral = integral + errors ;
    derivative = (errors - previous_error) ;
    output = Kp * errors + Ki * integral + Kd * derivative;
    int max_output = 100;
    previous_error = errors;
    if (output > max_output )output = max_output;
    else if (output < -max_output)output = -max_output;
    motor(1, speed_max - output);
    motor(2, speed_max + output);
    delay(1);
    
  } while (millis() - timer < delay_timer  );
}

void Run_until(){

  float Kp = 4 ;
  float Ki = 0;
  float Kd = 50;
  uint16_t setpoint;
  float present_position;
  float errors = 0;
  float output = 0;
  float integral ;
  float derivative ;
  float previous_error ;
  do {
    int speed_max = 35;
    present_position = readline() / ((numSensor - 1) * 10) ;
    setpoint = 50.0;
    errors = setpoint - present_position;
    integral = integral + errors ;
    derivative = (errors - previous_error) ;
    output = Kp * errors + Ki * integral + Kd * derivative;
    int max_output = 100;
    previous_error = errors;
    if (output > max_output )output = max_output;
    else if (output < -max_output)output = -max_output;
    motor(1, speed_max - output);
    motor(2, speed_max + output);
    delay(1);

  } while ((analogRead(_sensorPins[0]) > _min_sensor_values[0] + 300 || analogRead(_sensorPins[1]) > _min_sensor_values[1] + 300)  &&( analogRead(_sensorPins[6]) > _min_sensor_values[6] + 300 || analogRead(_sensorPins[7]) > _min_sensor_values[7] + 300));
  
}
void Run_until_B(){

  float Kp = 1.4 ;
  float Ki = 0;
  float Kd = 10;
  uint16_t setpoint;
  float present_position;
  float errors = 0;
  float output = 0;
  float integral ;
  float derivative ;
  float previous_error ;
  do {
    int speed_max = 40;
    present_position = readline() / ((numSensor - 1) * 10) ;
    setpoint = 50.0;
    errors = setpoint - present_position;
    integral = integral + errors ;
    derivative = (errors - previous_error) ;
    output = Kp * errors + Ki * integral + Kd * derivative;
    int max_output = 100;
    previous_error = errors;
    if (output > max_output )output = max_output;
    else if (output < -max_output)output = -max_output;
    motor(1, speed_max - output);
    motor(2, speed_max + output);
    delay(1);

  } while ((analogRead(_sensorPins[0]) > _min_sensor_values[0] + 300 || analogRead(_sensorPins[1]) > _min_sensor_values[1] + 300)  ||( analogRead(_sensorPins[6]) > _min_sensor_values[6] + 300 || analogRead(_sensorPins[7]) > _min_sensor_values[7] + 300));
  
}
void Run_until_W(){

  float Kp = 1.2 ;
  float Ki = 0;
  float Kd = 10;
  uint16_t setpoint;
  float present_position;
  float errors = 0;
  float output = 0;
  float integral ;
  float derivative ;
  float previous_error ;
  do {
    int speed_max = 40;
    present_position = readline() / ((numSensor - 1) * 10) ;
    setpoint = 50.0;
    errors = setpoint - present_position;
    integral = integral + errors ;
    derivative = (errors - previous_error) ;
    output = Kp * errors + Ki * integral + Kd * derivative;
    int max_output = 100;
    previous_error = errors;
    if (output > max_output )output = max_output;
    else if (output < -max_output)output = -max_output;
    motor(1, speed_max - output);
    motor(2, speed_max + output);
    delay(1);

  } while ( (analogRead(_sensorPins[0]) < avg[0])  || 
            (analogRead(_sensorPins[1]) < avg[1])  || 
            (analogRead(_sensorPins[2]) < avg[2])  || 
            (analogRead(_sensorPins[3]) < avg[3])  || 
            (analogRead(_sensorPins[4]) < avg[4])  || 
            (analogRead(_sensorPins[5]) < avg[5])  || 
            (analogRead(_sensorPins[6]) < avg[6])  || 
            (analogRead(_sensorPins[7]) < avg[7])   
          );
  
}

void square(int num){
  int x = 0;
  while(1){
    if(num==0)  break;
    else{
      if( analog(A0)<1000&&analog(A1)<1000 ){
        fd(30); delay(100);
        ao(); num -= 1; x=0;
        while(analog(A4)>500)  sl(30);
        
      }
      else if( analog(A4)<10000&&analog(A5)<1000 ){
         fd(30); delay(100);
        ao(); num -= 1; x=0;
        while(analog(A1)>500)  sr(30);

      }
      else if(analog(A1)>1000&&analog(A4)<1000){
        motor(1,40);
        motor(2,10);
      }
      else if(analog(A1)<1000&&analog(A4)>1000){
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
  NKP_ONE();
  Serial.begin(115200);
  IO15();
  setSensorPins((const int[]) {A0, A1, A2 , A3, A4, A5, A6, A7}, numSensor);
  // setSensorMax((const uint16_t[]){2400, 4001,4002,3500});
  // setSensorMin((const uint16_t[]){300, 301, 302, 303});
  for (int i = 0; i < 3; i++) {
    for(int l = 0;l<500;l++){
      setCalibrate();
      delay(1);
      motor(1,20);
      motor(2,20);  
    }
    aot(100);
    for(int l = 0;l<500;l++){
      setCalibrate();
      delay(1);
      motor(1,-20);
      motor(2,-20);  
    }aot(100);
    
    for(int l = 0;l<500;l++){
      setCalibrate();
      delay(1);
      motor(1,20);
      motor(2,20);  
    }aot(100);
    for(int l = 0;l<500;l++){
      setCalibrate();
      delay(1);
      motor(1,-20);
      motor(2,-20);  
    }
    aot(100);
    
  }
  aot(100);
  for (uint8_t i = 0; i < numSensor; i++)
  {
    Serial.print(ReadSensorMinValue(i));
    Serial.print(' ');
  }
  Serial.println();
  for (uint8_t i = 0; i < numSensor; i++)
  {
    Serial.print(ReadSensorMaxValue(i));
    Serial.print(' ');
  }
  for(int i=0;i<numm;i++){
    avg[i] = (_min_sensor_values[i]+_max_sensor_values[i])/2;
  }
  IO15();
  
  setSensitive(200);
}

void loop() {

fd(30); delay(1000); 
Run_until_B();
fd(30); delay(100);
Run_until();
fd(30); delay(50);
while(analog(A4)>1000)  sl(40);
Run_until_B();
fd(30); delay(50);
Run_fast(6000);
Run_slow(13000,1.2,0,10);
//ao(); delay(1000);
Run_until_W();
fd(30); delay(200);
Run_until_W();
fd(30); delay(200);
Run_until_W();
fd(30); delay(200);

Run_until_B();
fd(30); delay(50);
sl(40); delay(50);
while(analog(A2)>1000)  sl(40);
fd(30); delay(500);
//Run_until_W();
ao();
while(1);
}
