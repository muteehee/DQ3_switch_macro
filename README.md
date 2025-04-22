# DQ3 Remake Auto Leveling Macro for Nintendo Switch

An automated macro script for Dragon Quest III Remake on Nintendo Switch, built using Arduino with the `SwitchControlLibrary`.  
It simulates precise controller input via HID to automate movement and A-button presses, allowing hands-free level grinding.

（Nintendo Switch版ドラクエIIIリメイクでの自動レベル上げマクロ。ArduinoとSwitchControlLibraryを用いて、方向キー入力とAボタン連打を自動化します。）


## 🎯 Why I Built This

Repetitive grinding in RPGs is time-consuming and mentally exhausting.  
I wanted to explore how automation could reduce that burden — not through emulator cheats,  
but by controlling the actual Nintendo Switch hardware using an Arduino as a fake controller (HID spoofing).

By developing this macro, I learned how microcontrollers can emulate gamepad inputs and interact with real hardware in a practical, hands-free way.


## 🎮 Features

- Automates left-right movement and A-button mashing
- Works with Dragon Quest III Remake on Switch
- Built with `SwitchControlLibrary` and HID emulation
- Plug and play with Arduino Leonardo or compatible boards (e.g., Pro Micro)


## 🔧 Hardware Requirements

- Arduino Leonardo / Pro Micro (ATmega32u4搭載)
- USB cable (Micro-B)
- USB-A to USB-C adapter (if connecting directly to Switch)


## 🛠️ Development Environment

This project was developed and tested on **macOS**.  
Please note that file paths (such as `~/Library/Arduino15/...`) may differ on Windows or Linux environments.


## 📦 Required Library: SwitchControlLibrary

This project uses [SwitchControlLibrary](https://github.com/celclow/SwitchControlLibrary) by [procon-oss](https://github.com/procon-oss),  
which enables Arduino to act as a Nintendo Switch controller via USB HID.

You can install it via the Arduino Library Manager by searching for **"SwitchControlLibrary"**,  
or download it directly from GitHub:

👉 https://github.com/celclow/SwitchControlLibrary

> 📌 Note: If you need to modify `boards.txt` or adjust VID/PID settings, please refer to the instructions on the library’s GitHub page or related documentation.


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
```

## 🧾 In-game Setup (for DQ3 Remake on Switch)

To use the macro effectively, prepare your game environment as follows:

1. Move your character to a **leveling-friendly zone** (where enemies appear frequently).
2. Ensure there are **no walls or obstacles on the left and right** of the character.  
   Open fields are ideal for uninterrupted movement.
3. Set battle speed to **"超はやい (Fastest)"** in game settings for quicker battles.
4. Use **handheld mode** (not docked) for compatibility with USB HID via adapter.
5. Enable **"楽ちんプレイ (Easy Mode)"** to allow infinite auto-battling without death depletion.

（日本語まとめ）
- レベル上げゾーンにキャラを配置
- 左右に壁や障害物がない場所（フィールド推奨）
- 戦闘スピードは「超はやい」
- 携帯モードで操作（USB接続の都合上）
- 「楽ちんプレイ」をONにすることで、放置でも無限狩り可能


## 🚀 Future Plans

This project currently runs on a fixed loop of directional inputs and button presses.  
In the future, I plan to extend it by integrating **real-time image recognition** via Python or OpenCV on a PC.

The idea is to process video from the Switch (via HDMI capture),  
then analyze game states (e.g., battle start, character status, level-up screen)  
and dynamically send commands to the Arduino via serial interface.

This would turn the bot from a simple macro into a semi-intelligent automation system.

> Imagine a bot that only presses A when enemies appear, or stops grinding when HP is low.
