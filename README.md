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

## 🛠️ Development Environment

This project was developed and tested on **macOS**.  
Please note that file paths (such as `~/Library/Arduino15/...`) may differ on Windows or Linux environments.

## 📦 Required Library: SwitchControlLibrary
This project uses SwitchControlLibrary
by procon-oss, which enables Arduino to act as a Switch controller via HID.

You can install it via the Arduino Library Manager by searching for "SwitchControlLibrary",
or download it directly from GitHub:

👉 https://github.com/celclow/SwitchControlLibrary


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
