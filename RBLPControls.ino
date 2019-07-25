/* 
 *  RECALBOX - LATTEPANDA (ARDUINO LEONARDO) PLAYER 1 CONTROLLER ENCODER WITH FRONT END CONTROLS
 *  DERIVED FROM ROMBUSPINBALL https://github.com/circuitbeard/rombus-pinball
 *  Borrowed heavily from Pimoronis Picade sketch at https://github.com/pimoroni/Picade-Sketch/tree/master/Picade
 */

#include "RBLPControls.h"
#include "TimerOne.h"
#include <Keyboard.h>

#define DEBOUNCE_DELAY 25

const uint8_t user_pins[] = { BTN_P1_START, BTN_P1_SELECT, BTN_P1_UP, BTN_P1_DOWN, BTN_P1_LEFT, BTN_P1_RIGHT, BTN_P1_A, BTN_P1_B, BTN_P1_X, BTN_P1_Y, BTN_P1_L1, BTN_P1_R1, BTN_FE_HOTKEY, BTN_FE_ACCEPT, BTN_FE_BACK, BTN_FE_MENU, BTN_FE_QUITEM };
const uint8_t user_keys[] = { '1', '3', KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, 'z', KEY_LEFT_SHIFT, KEY_LEFT_ALT, KEY_LEFT_CTRL, ' ', 'x', 'c', 'a', 's', KEY_RETURN, KEY_ESC };

static button_state button_states[BUTTON_COUNT] = {};

void setup() {
  Serial.begin(9600);
  //while(!Serial);
  Serial.setTimeout(100);

  // Setup pins as input with pullup resistor
  for ( uint8_t i = 0; i < BUTTON_COUNT; i++ ) {



        pinMode(user_pins[i], INPUT_PULLUP);
   }

  Timer1.initialize(5000);
  Timer1.attachInterrupt(update);
  Timer1.start(); 
}

void update(void) {
  for (int i = 0; i < BUTTON_COUNT; i++)
  {
    uint8_t state;
    state = !digitalRead(user_pins[i]);
    if (state != button_states[i].state && (millis() - button_states[i].last_change) > DEBOUNCE_DELAY) // has this input changed state since the last time we checked?
    {
      button_states[i].state = state; // update our state map so we know what's happening with this key in future
      button_states[i].last_change = millis();
      handle_key(i, state);
    }
  }
}

bool handle_key(uint8_t i, uint8_t state) {
  uint8_t pin = user_pins[i];
  uint8_t key = user_keys[i];
  



  
  if (state) {
    Keyboard.press(key);
    digitalWrite(13, HIGH);
  } else {
    Keyboard.release(key);
    digitalWrite(13, LOW);
  }
}

void loop() {
  // Do nothing...
}
