# Lab 2: Blinky-Buzzy Toy
====================
## Introduction:

 The objective of our second project is to use the MSP430 Microcontroller to design a toy. 
 Each MSP430 board is equipped with buttons, LED's, a speaker, and an LED screen. 
 Utilizing these features we will develop a program to turn the board into a toy.
 
 This directory contains source code for a program "Blinkbuzz."
 
 This toy has the features of:

* generate sounds,
* dynamically change the LEDs that are illuminated, both brighly and dimmly,
* implement a state machine to maintain the state of the toy,
* and use the four buttons on the expansion board (P2.0-3) to transition the state machine.
 
 ### Milestone 1: Play with the demos folder
 The 'demos' directory contains sample programs for you to review and learn from. 
 These example programs are a great starting point in understanding how to program the MSP430 microcontroller. 
 See the readme in the demo directory on how to compile and run the demo programs.
 >\>

 ### Milestone 2: The Toy
 The 'project' directory  contain the source code for the toy. 
 
 
 #### Features 


## Compiling & Running the Code
To compile & execute the user interface program

While being inside this directory write on the terminal 
> make all
> 
This will compile the program, So to run it you'll write 
After thats done use "cd blinkbuzz/" to enter the blinkbuzz folder.
From there run the command
> 
> make load 
> 
 (this will trnsfer the code to the msp430 device)
 
## Cleaning Directory
To remove the compiled files and program

While being inside this directory write on the terminal 
> make clean
> 
This will delete any -.o & -.elf files as well as extra compiling files
