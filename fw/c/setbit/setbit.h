#ifndef _SETBIT_H_
#define _SETBIT_H_

typedef unsigned char uint8_t;
typedef unsigned int uint;

// TODO: (1) Add this function to setbit.c

// Get the bit at bitpos from the byte
extern uint getbit_in_byte(uint8_t byte,           // 8 bits
			   uint bitpos);            // 0-7 bit in byte

// TODO: (3) Add this function to setbit.c

// Set the bit at bitpos to value in byte without
// changing any other bits
extern void setbit_in_byte(uint8_t* byte,           // Pointer to 8 bits
			   uint bitpos,             // 0-7 bit in byte
			   uint value);             // 0 or 1 new bit value


#endif // _SETBIT_H_
