#include "libTimer.h"
#include "buzzer.h"
#include <msp430.h>

// define musical note and its frequency
#define A3 2273
#define B3 2025
#define G3 2551
#define E3 3033
#define C3 3846
#define C4 1911
#define D4 1703
#define E4 1517
#define F4 1432
#define G4 1276
#define A4 1136
#define B4 1012
#define C5 956


static int counter1 = 0; 
static int counter2 = 0; 
static int counter3 = 0; 

void buzzer_init(){
  /*
    Direct timer A output "TA0.1" to P2.6.
    According to table 21 from data sheet:
    P2SEL2.6, P2SEL2.7, and P2SEL.7 must be zero
    P2SEL.6 must be 1
    Also: P2.6 direction must be output
  */
  timerAUpmode(); //used to drive speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6; //enable output to speaker (P2.6)
}


void errorTone(){
  int notes[] = {E4,0,E4,0,C5,0,C5,B4,B4,500,0};

  for(int i = 0; i < sizeof(notes)/sizeof(*notes); i++) {
    buzzer_set_period(notes[i]);
    __delay_cycles(300000);
  }  
}

/*
  superMarioTheme is a method which calls the buzzer_set_period method
  from the buzzer.h file to produce the sound of the frequency specified on
  each case. When the method is called consistently, the song from the Super Mario
  game is played on the MSP430's speaker.
*/
void superMarioTheme(){
  switch(counter1){
  case 0:
  case 1:
  case 2:
  case 4: buzzer_set_period(750); counter1++; break; //E note
  case 3: buzzer_set_period(950); counter1++; break; //C note
  case 5: buzzer_set_period(630); counter1++; break; //G note
  case 6: buzzer_set_period(1260); counter1 = 0; break; //Lower G note
  }
}

/*
  starWarsTheme is a method which calls the buzzer_set_period method
  from the buzzer.h file to produce the sound of the frequency specified on
  each case. When the method is called consistently, the song from the Star Wars
  movie is played on the MSP430's speaker.
*/
void starWarsTheme(){
  switch(counter2){
  case 0: buzzer_set_period(950); counter2++; break; //Lower C note
  case 1:
  case 6:
  case 11: buzzer_set_period(630); counter2++; break; //G note
  case 2:
  case 7:
  case 12:
  case 14: buzzer_set_period(710); counter2++; break; //F note
  case 3:
  case 8:
  case 13: buzzer_set_period(750); counter2++; break; //E note
  case 4:
  case 9:
  case 15: buzzer_set_period(840); if(counter2==15){counter2 = 0;} else{counter2++;}; break;//D note
  case 5:
  case 10: buzzer_set_period(475); counter2++; break; //C note
  }
}

/*
  starSong is a method which calls the buzzer_set_period method
  from the buzzer.h file to produce the sound of the frequency specified on
  each case. When the method is called consistently, the song from the Super Mario
  game when you get a star is played on the MSP430's speaker.
*/
void starSong(){
  switch(counter3){
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 6:
  case 8: buzzer_set_period(950); counter3++; break; //C note
  case 5:
  case 7: buzzer_set_period(1130); counter3++; break; //A note
  case 9:
  case 10:
  case 11:
  case 12:
  case 13:
  case 15:
  case 17: buzzer_set_period(1000); if(counter3==17){counter3 = 0;} else{counter3++;}; break; //B
  case 14:
  case 16: buzzer_set_period(1270); counter3++; break; //G note
  }
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1; //one half cycle
}
