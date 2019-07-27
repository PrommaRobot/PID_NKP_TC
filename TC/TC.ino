#include "NKP_TCSensor.h"
#include <popx2.h>
void setup() {
  OK();
  Serial.begin(115200);
  setSensorPins((const int[]) {25, 26, 27 , 28}, 4);
  //setSensorMax((const int[]) {1, 2, 3, 4});
  //setSensorMin((const int[]) {5, 6, 7, 8});
  for(int i = 0;i<5000;i++){
    setCalibrate();
    }
  for (uint8_t i = 0; i < 4; i++)
  {
    Serial.print(ReadSensorMinValue(i));
    Serial.print(' ');
  }
  Serial.println();
  for (uint8_t i = 0; i < 4; i++)
  {
    Serial.print(ReadSensorMaxValue(i));
    Serial.print(' ');
  }
  Serial.println();
  delay(1000);
}

void loop() {
  /*Serial.print("  readline");
  Serial.println(readline());
  delay(1);*/
  /*for (int i = 1; i <= 4; i++)
  {
    glcd(i, 0, "%d   ", analog(i));
  }*/
}
