#ifndef _SETBIT_H_
#define _SETBIT_H_

typedef unsigned char uint8_t;
typedef unsigned int uint;

// TODO: (1) Add this function to bitstring.cpp

// Get the bit at bitpos to value in bitstr
#define TEST1 0 // Change to 1 when ready to test get_bit_in_bitstr
extern uint8_t get_bit_in_bitstr(uint8_t* bitstr,       // Pointer to 8 bits
                                 uint bitpos);          // Bit in bitstr


// TODO: (3) Add this function to bitstring.cpp


// Set the bit at bitpos to value in bitstr without
// changing any other bits
#define TEST2 0 // Change to 1 when ready to test set_bit_in_bitstr
extern void set_bit_in_bitstr(uint8_t* bitstr,       // Pointer to 8 bits
                              uint bitpos,           // Bit in bitstr
                              uint value);           // 0 or 1 new bit value


// TODO: (5) Add this function to bitstring.cpp

// Insert one bitstr into the middle of another bitstr
extern uint8_t *insert_bitstr(uint8_t *init_bitstr,  // Initial bitstr
                              uint init_bitstr_len,  // Length of init bitstr in bits
                              uint8_t *ins_bitstr,  // Bitstr to insert
                              uint ins_bitstr_len,  // Length of insert bitstr in bits
                              uint insert_point);  // Position in initial bitstr
                                                   // (in bits) where the
                                                   // ins_bitstr should be inserted

#endif // _SETBIT_H_
