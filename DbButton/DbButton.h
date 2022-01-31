#ifndef DbButton_h
#define DbButton_h

#include "Arduino.h"
class DbButton{
  public:
    DbButton(int pin);
    void btnLoop(void);
    int getState(void);
    static void setDebounceTime(unsigned long int time);
  private:
    int _pin;
    int _lastButtonState;
    int _toggleState;
    unsigned long int _lastPressTime;
    static unsigned long int _debounceTime;
};


#endif
