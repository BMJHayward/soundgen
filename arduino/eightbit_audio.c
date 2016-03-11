/*
To compile this on arduino uno:
$ avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o eightbit_audio.o eightbit_audio.c
$ avr-gcc -mmcu=atmega328p led.o -o led
$ avr-objcopy -O ihex -R .eeprom led led.hex
$ avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:led.hex
 
The first command line takes the C source file and compiles it into an object file. 
The options tell the compilerto optimize for code size,what is the clock frequency (it’s useful for delay functions for example) 
and which is the processor for which to compile code. The second commands links the object file together with system libraries 
(that are linked implicitly as needed) into an ELF program. The third command converts the ELF program into an IHEX file. 
The fourth command uploads the IHEX data ito the Atmega chip embedded flash, and the options tells avrdude program to 
communicate using the Arduino serial protocol, through a particular serial port which is the Linux device “/dev/ttyACM0“, and to 
use 115200bps as the data rate.

SOURCE: https://balau82.wordpress.com/2011/03/29/programming-arduino-uno-in-pure-c/
DATE_LAST_ACCESSED: 20160211
*/
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

void stopPlayback()
{
    return 0;
}


void startPlayback()
{
    return 0;
}


void setup()
{
    return 0;
}


void loop()
{
    while(true);
}

