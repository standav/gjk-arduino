#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}

void loop() {
  if (mySerial.available()) {
    mySerial.write(0x63);
    delay(100);
  }
}
