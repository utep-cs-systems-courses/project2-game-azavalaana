# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blinkbuzz.elf 

#additional rules for files
blinkbuzz.elf: ${COMMON_OBJECTS} p2_interrupt_handler.o led.o switches.o blinkbuzzMain.o buzzer.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinkbuzz.elf
	#mspdebug rf2500 "prog blinkbuzz.elf"
	msp430loader.sh blinkbuzz.elf

clean:
	rm -f *.o *.elf *~

