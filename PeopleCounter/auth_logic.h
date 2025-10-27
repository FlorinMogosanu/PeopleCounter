#ifndef AUTH_LOGIC_H
#define AUTH_LOGIC_H

void startPasswordChange();
void handleConfirmOldPassword(char key);
void handleSetPassword(char key);
void handleCheckPassword(char key);
void handleLogout();

#endif // AUTH_LOGIC_H
