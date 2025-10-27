#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <Keypad.h>
#include <EEPROM.h>

// --- Keypad Setup ---
#define ROWS 4
#define COLS 4
extern char keys[ROWS][COLS];
extern byte rowPins[ROWS];
extern byte colPins[COLS];

// --- Constants ---
#define MAX_COUNT 500000UL // Maximum storable value

// --- Pins for Buttons + LED ---
const byte INCREMENT_BTN = 2;
const byte DECREMENT_BTN = 3;
const byte RESET_BTN = 4;
const byte WARNING_LED = 5;

// --- EEPROM Adresses ---
const int addrPassword = 0;
const int addrMaxCount = 20;

// --- Debounce Timing ---
const unsigned long debounceDelay = 500;

// --- Global Variable Declarations (extern) ---
// 'extern' tells the compiler these variables exist and are defined elsewhere (in the .ino file)
extern Keypad keypad;
extern unsigned int peopleCounter;
extern unsigned long maxCount;
extern bool isWarningLedOn;
extern String password;
extern String input;
extern bool settingPassword;
extern bool confirmingPassword;
extern bool loggedIn;
extern bool settingMaxCount;
extern unsigned long lastDebounceTimeBtnPress;

#endif // CONFIG_H
