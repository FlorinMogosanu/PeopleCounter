#include "config.h"
#include "input_handler.h"

/**
 * @brief Processes keypad input, building a string until '#' is pressed.
 * @return True if '#' was pressed (entry confirmed), false otherwise.
 */
bool processInput(char key) {
  if (key == '*') {
    input = ""; // Clear current input
    Serial.println("(Input cleared)");
  }  
  else if (key == '#') {
    return true;  // Entry is complete
  }  
  else if (isdigit(key)) {
      // Limit password entry to 4 digits
      if ((settingPassword || confirmingPassword || !loggedIn) && input.length() >= 4) {
          return false; // Don't add more than 4 digits for passwords
      }
      // Limit max count entry to 6 digits
      if (settingMaxCount && input.length() >= 6) {
          return false; // Don't add more than 6 digits for max count
      }
      input += key;
  }
  return false;
}
