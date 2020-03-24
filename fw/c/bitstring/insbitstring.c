#include <stdlib.h>

#include "bitstring.h"

uint8_t *insert_bitstr(uint8_t *init_bitstr,  // Initial bitstr
                              uint init_bitstr_len,  // Length of init bitstr in bits
                              uint8_t *ins_bitstr,  // Bitstr to insert
                              uint ins_bitstr_len,  // Length of insert bitstr in bits
                              uint insert_point)  // Position in initial bitstr
                                                   // (in bits) where the
                                                   // ins_bitstr should be inserted

{
    uint8_t *res = malloc((init_bitstr_len + ins_bitstr_len + 7) % 8);


    return res;
}
