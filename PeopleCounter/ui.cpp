#include "config.h"
#include "ui.h"

/**
 * @brief Prints the main status screen to the Serial Monitor.
 */
void printStatus() {
  Serial.println("--------------------");
  Serial.print("People Count: ");
  Serial.println(peopleCounter);
  Serial.println("--------------------");
}

/**
 * @brief Prints the main welcome/login message.
 */
void printWelcomeMessage() {
  Serial.println("\nPlease enter your 4-digit password (end with #).");
  Serial.println("Press 'A' to change password.");
}

/**
 * @brief Prints the menu of available commands when logged in.
 */
void printLoggedInMenu() {
  Serial.println("\n--- Logged In ---");
  printStatus();
  Serial.println("Commands:");
  Serial.println("  A - Change Password");
  Serial.println("  B - Set Max People Count");
  Serial.println("  C - Show Max People Count");
  Serial.println("  D - Logout");
  Serial.println("Use hardware buttons to increment, decrement, or reset count.");
}
