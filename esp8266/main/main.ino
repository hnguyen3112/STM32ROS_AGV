#include <SoftwareSerial.h>
SoftwareSerial mySerial(13, 15); // RX, TX
void setup() {
  Serial.begin(115200);
  Serial.setTimeout(50);
  mySerial.begin(115200);
  mySerial.setTimeout(50);
}

void loop() {
    if (Serial.available()) {
      String str = Serial.readString();
      mySerial.print(str);
    }
    if (mySerial.available()) {
      String str = mySerial.readString();
      Serial.print(str);
    }
}
