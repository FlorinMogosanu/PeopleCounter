#include "config.h"
#include "eeprom_utils.h"
#include "auth_logic.h"
#include "counter_logic.h"
#include "ui.h"
#include "input_handler.h"

// --- Global Variable Definitions ---
// These are the actual variables that store the program's state.
unsigned int peopleCounter = 0;
unsigned long maxCount = 100;
bool isWarningLedOn = false;
String password;
String input = ""; 

// --- State Flags ---
bool settingPassword = false;
bool confirmingPassword = false;
bool loggedIn = false;
bool settingMaxCount = false;

// --- Debounce Timing ---
unsigned long lastDebounceTimeBtnPress = 0;

// --- Keypad hardware definition ---
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// =================================================================
// --- SETUP ---
// =================================================================
void setup(){
  pinMode(INCREMENT_BTN, INPUT_PULLUP);
  pinMode(DECREMENT_BTN, INPUT_PULLUP);
  pinMode(RESET_BTN, INPUT_PULLUP);
  pinMode(WARNING_LED, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("\n--- People Counter V1.0 Initialized ---");

  // Load data from EEPROM
  password = readStringFromEEPROM(addrPassword);
  EEPROM.get(addrMaxCount, maxCount);
  
  // Check if a password exists
  if (password.length() == 0) {
    Serial.println("No password found.");
    Serial.println("Please set a new 4-digit password (end with #):");
    settingPassword = true;
  } else {
    printWelcomeMessage();
  }

  // Validate maxCount
  if (maxCount == 0 || maxCount > MAX_COUNT) {
    maxCount = 100;
    EEPROM.put(addrMaxCount, maxCount);
  }
}

// =================================================================
// --- MAIN LOOP ---
// =================================================================
void loop(){
  char key = keypad.getKey();
  unsigned long currentMillis = millis();

  // Handle keypad input
  if(key){
    if (key == 'A') {
      startPasswordChange();
    }
    else if(loggedIn && key == 'B'){
      startMaxPeopleSet();
    }
    else if (loggedIn && key == 'C' && !settingMaxCount && !confirmingPassword && !settingPassword) {
      handleShowMaxCount();
    }
    else if (loggedIn && key == 'D' && !settingMaxCount && !confirmingPassword && !settingPassword) {
      handleLogout();
    }
    else if(settingMaxCount){
      handleMaxPeopleSet(key);
    }
    else if (settingPassword) {
      handleSetPassword(key);
    } 
    else if (confirmingPassword) {
      handleConfirmOldPassword(key);
    } 
    else if (!loggedIn) {
      handleCheckPassword(key);
    }
  }
  
  // Handle physical button presses
  if (loggedIn && (currentMillis - lastDebounceTimeBtnPress >= debounceDelay)) {
      if (digitalRead(INCREMENT_BTN) == LOW) {
        handleIncrement();
        lastDebounceTimeBtnPress = currentMillis;
      }
      else if (digitalRead(DECREMENT_BTN) == LOW) {
        handleDecrement();
        lastDebounceTimeBtnPress = currentMillis;
      }
      else if (digitalRead(RESET_BTN) == LOW) {
        handleReset();
        lastDebounceTimeBtnPress = currentMillis;
      }
  }
  
  // Control the warning LED
  if (peopleCounter >= maxCount && !isWarningLedOn) {
    digitalWrite(WARNING_LED, HIGH);
    isWarningLedOn = true;
  } else if (peopleCounter < maxCount && isWarningLedOn) {
    digitalWrite(WARNING_LED, LOW);
    isWarningLedOn = false;
  }
}
