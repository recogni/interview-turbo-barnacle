#include <stdio.h>
#include <assert.h>

#include "bitstring.h"

//
// A bitstring is an array of bytes that is just considered to be a string of bits
//
// Example:
//  The bitstring {0x01, 0x02, 0x03} has at most 24 bits,  The zero-th bit is one
//  (the least significant bit of the first byte) as are the 9th (second bit in
//  the second byte), 16th, and 17th bits.  All other bits in the bitstring
//  are zero.

int main(const int argc, const char** argv)
{
    /*
     * TODO (2)
     */

#if TEST1
    uint8_t testbitstr1[10] = {0x00, 0x00, 0x03, 0x00, 0x40,
                               0x00, 0x00, 0x00, 0x00, 0x00};
     assert(get_bit_in_bitstr(testbitstr1, 38) == 1);
     assert(get_bit_in_bitstr(testbitstr1, 37) == 0);
     assert(get_bit_in_bitstr(testbitstr1, 39) == 0);
     assert(get_bit_in_bitstr(testbitstr1, 16) == 1);
     assert(get_bit_in_bitstr(testbitstr1, 17) == 1);
     assert(get_bit_in_bitstr(testbitstr1, 15) == 0);
     assert(get_bit_in_bitstr(testbitstr1, 18) == 0);
#else
     printf("Test 1 pending\n");
#endif     


    /*
     * TODO (4)
     */

#if TEST2
     uint8_t testbitstr2[10] = {0x00, 0x00, 0x00, 0x00, 0x00,
                                0x00, 0x00, 0x00, 0x00, 0x00};
     set_bit_in_bitstr(testbitstr2, 42, 1);
     for (int i = 0; i < 10; i++)
     {
        if (i == 5) {
          assert(testbitstr2[i] == 0x04);
        } else {
          assert(testbitstr2[i] == 0x00);
        }
     }

     uint8_t testbitstr3[10] = {0xff, 0xff, 0xff, 0xff, 0xff,
                                0xff, 0xff, 0xff, 0xff, 0xff};
     set_bit_in_bitstr(testbitstr3, 57, 0);
     for (int i = 0; i < 10; i++)
     {
        if (i == 7) {
          assert(testbitstr3[i] == 0xfd);
        } else {
          assert(testbitstr3[i] == 0xff);
        }
     }
#else
     printf("Test 2 pending\n");
#endif     

    /*
     * TODO (6)
     */

#if TEST3     
     uint8_t init_bitstr1[10] = {0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00};
     uint8_t insert_bitstr1[5] = {0xff, 0xff, 0xff, 0xff, 0xff};
    
     uint8_t *result1;
    
     result1 = insert_bitstr(init_bitstr1, 73, insert_bitstr1, 37, 12);
     for (int i = 0; i < 12; i++)
     {
         assert(get_bit_in_bitstr(result1, i) == 0);
     }
     for (int i = 12; i < 12 + 37; i++)
     {
         assert(get_bit_in_bitstr(result1, i) == 1);
     }
     for (int i = 12 + 37; i < 37 + 73; i++)
     {
         assert(get_bit_in_bitstr(result1, i) == 0);
     }
#else
     printf("Test 3 pending\n");
#endif     

    /*
     *  TODO (7) :: Remove me!!
     */
    printf("Edit bitstring.c and insbitstring.c to implement each function");
}
