#include "config.h"
#include "auth_logic.h"
#include "input_handler.h"
#include "ui.h"
#include "eeprom_utils.h"

/**
 * @brief Initiates the password change process.
 */
void startPasswordChange() {
  Serial.println("\n--- Change Password ---");
  Serial.println("Please enter your OLD 4-digit password (end with #):");
  confirmingPassword = true;
  loggedIn = false;
  input = "";
}

/**
 * @brief Handles keypad input while confirming the old password.
 */
void handleConfirmOldPassword(char key) {
  if (processInput(key)) {
    if (input == password) {
      Serial.println("Correct. Please enter your NEW 4-digit password (end with #):");
      confirmingPassword = false;
      settingPassword = true;
    } else {
      Serial.println("Wrong password. Returning to main screen.");
      confirmingPassword = false;
      loggedIn = true; // Log back in
      printLoggedInMenu();
    }
    input = "";
  }
}

/**
 * @brief Handles keypad input while setting a new password.
 */
void handleSetPassword(char key) {
  if (processInput(key)) {
    if (input.length() == 4) {
      password = input;
      writeStringToEEPROM(addrPassword, password);
      Serial.println("Password saved successfully!");
      settingPassword = false;
      loggedIn = true;
      printLoggedInMenu();
    } else {
      Serial.println("Error: Password must be exactly 4 digits. Please try again.");
      Serial.println("Enter new 4-digit password (end with #):");
    }
    input = "";
  }
}

/**
 * @brief Checks the entered password for login.
 */
void handleCheckPassword(char key) {
  if (processInput(key)) {
    if (input == password) {
      Serial.println("Access Granted.");
      loggedIn = true;
      printLoggedInMenu();
    } else {  
      Serial.println("Access Denied. Incorrect password.");
      printWelcomeMessage();
    }
    input = "";
  }
}

/**
 * @brief Logs the user out.
 */
void handleLogout() {
    Serial.println("\nLogging out...");
    loggedIn = false;
    printWelcomeMessage();
}
