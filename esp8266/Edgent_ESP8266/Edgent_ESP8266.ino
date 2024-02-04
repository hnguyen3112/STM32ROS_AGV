#define BLYNK_TEMPLATE_ID "TMPL6SzFxVLue"
#define BLYNK_TEMPLATE_NAME "MH"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"

//#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_NODE_MCU_BOARD
#include "BlynkEdgent.h"

WidgetTerminal t(V0);
BlynkTimer timer;

#include <SoftwareSerial.h>
SoftwareSerial mySerial(13, 15); // RX, TX
String dt[5];

#include "control.h"

void setup()
{
  BlynkEdgent.begin();
  Serial.begin(115200);
  Serial.setTimeout(50);
  mySerial.begin(115200);
  mySerial.setTimeout(50);
  timer.setInterval(2000L, send_data);
}
void process_data(String data) {
  int a = data.indexOf(" ");
  dt[0] = data.substring(0, a);
  int b = data.indexOf(" ", a + 1);
  dt[1] = data.substring(a + 1, b);
  int c = data.indexOf(" ", b + 1);
  dt[2] = data.substring(b + 1, c);
  int d = data.indexOf(" ", c + 1);
  dt[3] = data.substring(c + 1, d);
  int e = data.indexOf(" ", d + 1);
  dt[4] = data.substring(d + 1, e);

  Serial.print(dt[0]); Serial.print("  ");
  Serial.print(dt[1]); Serial.print("  ");
  Serial.print(dt[2]); Serial.print("  ");
  Serial.print(dt[3]); Serial.print("  ");
  Serial.print(dt[4]); Serial.println("  ");
}
void loop() {
  BlynkEdgent.run();
  timer.run();
  if (Serial.available()) {
    String str = Serial.readString();
    mySerial.print(str);
  }
  if (mySerial.available()) {
    String str = mySerial.readString();
    process_data(str);
    Serial.print(str);
  }
}
