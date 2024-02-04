BLYNK_WRITE(V0) { //teminal
}
BLYNK_WRITE(V1) { //T
  int p = param.asInt();
}
BLYNK_WRITE(V2) { //H
  int p = param.asInt();
}
BLYNK_WRITE(V3) { //D
  int p = param.asInt();
}
BLYNK_WRITE(V4) {  //O-F
  int p = param.asInt();
  if (p == 1) {
    mySerial.print("OOOOOOOO__");
  }
  else {
    mySerial.print("FFFFFFFF__");
  }
}
void send_data() {
  Blynk.virtualWrite(V1, dt[2].toInt());
  Blynk.virtualWrite(V2, dt[3].toInt());
  Blynk.virtualWrite(V3, dt[4].toInt());
  t.println("Newdata");
}
