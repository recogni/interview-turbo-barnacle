#include "stdio.h"

typedef unsigned char byte;
typedef unsigned int  uint;


/*
 *  print the contents of the byte buffer.
 */
void print_buffer(/* TODO */)
{
}

/*
 *  `insert_bits` accepts a byte buffer `pbuf` with `n` bits of significant
 *  data, the value `v` which is `v_bits` wide (0 - 8) is inserted into the
 *  buffer at position `v_loc`. All bits are after `v_loc` are shifted off
 *  to the right if they fall off the lsb.
 */
void insert_bits(
    byte *pbuf,
    const uint n,
    const uint v,
    const uint v_bits,
    const uint v_loc)
{
    /* TODO */
}

/*
 *  `main` application entry-point.
 */
int main(int argc, char **argv)
{
    byte buffer[] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};

    // Checkpoint 1 :: implement a `print_buffer` method and invoke it.
    print_buffer(/* TODO */);

    // Checkpoint 2 :: implement the guts of `insert_bits` to satisfy
    //                 the below condition.
    insert_bits(&buffer[0], 64, 0xF0, 8, 16);

    print_buffer(/* TODO */);
}
