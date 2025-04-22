# DQ3 Remake Auto Leveling Macro for Nintendo Switch

An automated macro script for Dragon Quest III Remake on Nintendo Switch, built using Arduino with the `SwitchControlLibrary`.  
It simulates precise controller input via HID to automate movement and A-button presses, allowing hands-free level grinding.

（Nintendo Switch版ドラクエIIIリメイクでの自動レベル上げマクロ。ArduinoとSwitchControlLibraryを用いて、方向キー入力とAボタン連打を自動化します。）


## 🎮 Features

- Automates left-right movement and A-button mashing
- Works with Dragon Quest III Remake on Switch
- Built with `SwitchControlLibrary` and HID emulation
- Plug and play with Arduino Leonardo or compatible boards (e.g., Pro Micro)


## 🔧 Hardware Requirements

- Arduino Leonardo / Pro Micro (ATmega32u4搭載)
- USB cable (Micro-B)
- USB-A to USB-C adapter (if connecting directly to Switch)


## 🚀 Usage Instructions

1. Upload the `DQ3_auto_leveling.ino` sketch to your Arduino using Arduino IDE.
2. Connect the Arduino to your Nintendo Switch.
3. Place your character in a leveling zone in DQ3.
4. The macro will automatically press A and move left/right in loop.


## 🧠 Code Explanation

```cpp
#include <SwitchControlLibrary.h>

void setup() {
  // Initialize HID library
  SwitchControlLibrary();
}

void loop() {
  // Press A button
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(100);

  // Move stick right
  SwitchControlLibrary().MoveLeftStick(255, 128);
  delay(200);

  // Move stick left
  SwitchControlLibrary().MoveLeftStick(0, 128);
  delay(200);
}
