#include <SPI.h> //Library for using SPI Communication
#include <mcp2515.h> //Library for using CAN Communication
struct can_frame canMsg1; //LED ON OFF
MCP2515 mcp2515(10); // chip select pin 10

void setup()
{
Serial.begin(9600);
SPI.begin();
mcp2515.reset();
mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ);
mcp2515.setNormalMode();
canMsg1.can_id = 0x10;
canMsg1.can_dlc = 1;
}

void loop()
{
canMsg1.data[0]= 120;
mcp2515.sendMessage(&canMsg1);
delay(200);
canMsg1.data[0]= 250;
mcp2515.sendMessage(&canMsg1);
delay(200);
}