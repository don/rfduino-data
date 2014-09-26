// RFduino test receiving bytes from PhoneGap app
#include <RFduinoBLE.h>

void setup() {
  // Rename Peripheral
  RFduinoBLE.deviceName = "RFduinoBytes";
  RFduinoBLE.advertisementData = "";
  
  // start the BLE stack
  RFduinoBLE.begin();
  Serial.begin(9600);
  Serial.println("Hello");
}

void loop() {
  // go into low power mode
  RFduino_ULPDelay(INFINITE);
}

void RFduinoBLE_onReceive(char *data, int len) {
  
  // print each byte in multiple formats
  Serial.println("DEC HEX OCT BIN");
  for (int i = 0; i < len; i++) {
    Serial.print(data[i], DEC);
    Serial.print(" ");
    Serial.print(data[i], HEX);
    Serial.print(" ");
    Serial.print(data[i], OCT);
    Serial.print(" ");
    Serial.println(data[i], BIN);
//  Values may not be printable chars
//    Serial.print(" ");
//    Serial.println(data[i]);
  }
}
