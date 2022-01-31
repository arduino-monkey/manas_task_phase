#define btn 7
#define led 13
void setup() {
  pinMode(btn, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, !(digitalRead(btn)));
}
