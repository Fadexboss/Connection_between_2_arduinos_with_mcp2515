#include <SPI.h> //Library for using SPI Communication
#include <mcp2515.h> //Library for using CAN Communication

struct can_frame canMsg;
MCP2515 mcp2515(10); // chip select pin 10

void setup(){
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  SPI.begin(); //Begins SPI communication

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ); //Sets CAN at speed 250KBPS and Clock 8MHz
  mcp2515.setNormalMode();
  }

  void loop() {
  int a;
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK){
    if (canMsg.can_id == 0x10){
      a = canMsg.data[0];
      Serial.println(a);
    }
  }
  if(a == 0){
    digitalWrite(7,LOW);
    

  }
  if(a == 1){
    Serial.print("ez");
    
  }
}