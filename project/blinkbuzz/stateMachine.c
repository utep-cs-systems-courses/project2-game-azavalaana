#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"

// this method is used as a state machine for our project
// each case is dictated by which button is pressed from our switches.c file
void state_advance(){
  switch(state){
  case 1:
    //tempo = 97;
    errorTone();
    greenLights();
    state = 0;
    break;
  case 2:
    //tempo = 50;
    superMarioTheme();
    dimBlink();
    state = 0;
    break;
  case 3:
    //tempo = 120;
    starWarsTheme();
    redLights();
    starWarsTheme();
    greenLights();
    state = 0;
    break;
  case 4:
    //tempo = 22;
    starSong();
    bothLights();
    state = 0;
    break;
  default:
    break;
  }
}
