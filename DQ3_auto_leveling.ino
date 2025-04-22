#include <SwitchControlLibrary.h>

void setup() {
  SwitchControlLibrary();
}

void loop() {
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(100);

  SwitchControlLibrary().MoveLeftStick(255, 128);
  delay(200);
  SwitchControlLibrary().MoveLeftStick(0, 128);
  delay(200);
}
