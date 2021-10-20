#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char toggle_state, switch_state_down, switch_state_changed; /* effectively boolean */

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  if (p2val & SW1 ? 0 : 1){
    // toggle_state = 1;
    stateCall(1);
  }
  if (p2val & SW2 ? 0 : 1){
    // toggle_state = 2;
    stateCall(2);
  }
  if (p2val & SW3 ? 0 : 1){
    // toggle_state = 3;
    stateCall(3);
  }
  if (p2val & SW4 ? 0 : 1){
    // toggle_state = 4;
    stateCall(4);
  }
  //  led_update();
    //  switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
    //  switch_state_changed = 1;
}

void stateCall(int state) {
  switch(state){
  case 1:
    randomSong();
    greenLights();
    break;
  case 2:
    redLights();
    break;
  case 3:
    redLights();
    greenLights();
    break;
  case 4:
    randomSong();
    bothLights();
    break;
  default:
    break;
  }
}
