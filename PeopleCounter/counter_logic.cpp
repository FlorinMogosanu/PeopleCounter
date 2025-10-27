#include "config.h"
#include "counter_logic.h"
#include "input_handler.h"
#include "ui.h"

/**
 * @brief Initiates the process to set a new maximum people count.
 */
void startMaxPeopleSet(){
  Serial.println("\nEnter new max count (end with #):");
  settingMaxCount = true;
  input = "";
}

/**
 * @brief Handles keypad input while setting the max people count.
 */
void handleMaxPeopleSet(char key){
  if(processInput(key)){
    unsigned long newMaxCount = input.toInt();
    if(newMaxCount > 0 && newMaxCount <= MAX_COUNT){
      maxCount = newMaxCount;
      EEPROM.put(addrMaxCount, maxCount);  
      Serial.print("Max count set to: ");
      Serial.println(maxCount);
    }
    else{
      Serial.println("Error: Invalid value. Max count not changed.");
    }
    settingMaxCount = false;
    input = "";
    printLoggedInMenu(); // Show menu again
  }
}

/**
 * @brief Displays the currently set maximum people count.
 */
void handleShowMaxCount() {
    Serial.print("Current maximum people count is: ");
    Serial.println(maxCount);
}

/**
 * @brief Increments the people counter if not at max.
 */
void handleIncrement(){
  if(peopleCounter < maxCount) {
    peopleCounter++;
    printStatus();
  } else {
    Serial.println("Cannot increment: Max count reached!");
  }
}

/**
 * @brief Decrements the people counter if not at zero.
 */
void handleDecrement(){
  if (peopleCounter > 0) {
    peopleCounter--;
    printStatus();
  }
}

/**
 * @brief Resets the people counter to zero.
 */
void handleReset(){
  if (peopleCounter != 0) {
    peopleCounter = 0;
    Serial.println("Counter has been reset.");
    printStatus();
  }
}
