# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf 

#additional rules for files
main.elf: ${COMMON_OBJECTS} blinkbuzzMain.o p2_interrupt_handler.o led.o switches.o buzzer.o ../project/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf

blinkbuzzMain.c: buzzer.h led.h switches.h
switches.c: switches.h
led.c: led.h
buzzer.c: buzzer.h
p1_interrupt_handler.c: switches.h
