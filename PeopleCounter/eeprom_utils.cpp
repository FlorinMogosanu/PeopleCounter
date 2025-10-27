#include "eeprom_utils.h"
#include <EEPROM.h>

/**
 * @brief Writes a String to a specified EEPROM address.
 */
void writeStringToEEPROM(int addrOffset, const String &strToWrite) {
  byte len = strToWrite.length();
  EEPROM.write(addrOffset, len);
  for (int i = 0; i < len; i++) {
    EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
  }
}

/**
 * @brief Reads a String from a specified EEPROM address.
 */
String readStringFromEEPROM(int addrOffset) {
  int newStrLen = EEPROM.read(addrOffset);
  // Basic validation to check for corrupted data
  if (newStrLen > 32 || newStrLen < 0) return "";  
  char data[newStrLen + 1];
  for (int i = 0; i < newStrLen; i++) {
    data[i] = EEPROM.read(addrOffset + 1 + i);
  }
  data[newStrLen] = '\0'; // Null-terminate the string
  return String(data);
}
