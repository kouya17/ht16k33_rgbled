#include <Arduino.h>
#include "ht16k33LED.hpp"

Ht16k33led led0(0x70, 0, true);
Ht16k33led led1(0x70, 1, false);

void setup(){
  Serial.begin(115200);
  Serial.println("start.");
  led0.init();
  led1.init();
}

void loop(){
  unsigned int count = 0;
  while(true){
    if(count % 3 == 0){
      led0.write_rgb(1, 0, 0);
      led1.write_rgb(0, 1, 0);
    }else if(count % 3 == 1){
      led0.write_rgb(0, 1, 0);
      led1.write_rgb(0, 0, 1);
    }else{
      led0.write_rgb(0, 0, 1);
      led1.write_rgb(1, 0, 0);
    }

    count++;
    delay(1000);
  }
}