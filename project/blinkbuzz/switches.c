#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "led.h"
#include "libTimer.h"

//char switch_state_down, switch_state_changed; /* effectively boolean */
char switch_state_down, switch_state_changed, tempo;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  //switch_update_interrupt_sense();
  //switch_interrupt_handler();
  //led_update();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  //switch_state_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  if(p2val & SW1 && p2val & SW2 && p2val & SW3 && p2val & SW4){
    buzzer_set_period(0);
    switch_state_down = 0;
  }
  
  else if(!(p2val & SW1)){
    //Play Iron Man by Black Sabbath
    tempo = 97;
    ironManSong();
    switch_state_down = 1;
  }
  else if(!(p2val & SW2)){
    //Play the Super Mario theme song
    tempo = 50;
    superMarioTheme();
    switch_state_down = 1;
  }
  else if(!(p2val & SW3)){
    //Play the Star Wars theme song
    tempo = 120;
    starWarsTheme();
    switch_state_down = 1;
  }
  else if(!(p2val & SW4)){
    //Play the star song from Super Mario games
    tempo = 22;
    starSong();
    switch_state_down = 1;
  }
  switch_state_changed = 1;
  led_update();
}

