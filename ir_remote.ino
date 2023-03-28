#include <IRremote.h>

const int IR_SEND_PIN = 7;

uint16_t VENTIL_ZERO[] = {1280,420, 1280,370, 430,1270, 380,1270, 430,1270, 430,1220, 430,1270, 1280,420, 380,1270, 430,1270, 380,1270, 430};
uint16_t VENTIL_ONE[] = {1230,470, 1180,520, 380,1270, 430,1270, 380,1270, 1180,520, 380,1270, 430,1270, 380,1270, 430,1270, 1180,470, 1230};
uint16_t VENTIL_TWO[] = {1280,420, 1280,370, 430,1270, 430,1220, 430,1270, 430,1220, 430,1270, 430,1220, 480,1220, 1280,420, 430,1220, 430};
uint16_t VENTIL_THREE[] = {1280,420, 1230,420, 430,1270, 430,1220, 430,1270, 430,1220, 430,1270, 430,1220, 480,1220, 430,1220, 480,1220, 1280};

void setup(){
  Serial.begin(9600);
  IrSender.begin(IR_SEND_PIN);
}

void loop(){

      String input = Serial.readString();
      input.trim();
      if(input == "send"){
        Serial.print("You typed: " );
        Serial.println(input);
        IrSender.sendRaw(VENTIL_ONE, sizeof(VENTIL_ONE) / sizeof(VENTIL_ONE[0]), NEC_KHZ);
        delay(1000); // wait for one second
      }           
}