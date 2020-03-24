#include <stdio.h>
#include <stdint.h>


/*
 *  You are reading sensor raw values from a batch buffer to uint8_t array.
 *  However, these values need to be rearranged to uint16_t to make sense.
 *  For example, {0xab, 0xcd, 0x12, 0x34, 0x56, 0xab, 0xcd ..} would become
 *
 *  {0xabc, 0xd12, 0x345, 0x6ab ....}
 *
 *  Write a routine to rearrange the raw sensor values to actual real values.
 *  Also, write the driver function to test it.
 */
void sensorOut(uint8_t *pSensIn, int size, uint16_t* pSensOut)
{

	return;
}
/*
 *  `main` application entry-point.
 */
int main(int argc, char **argv)
{

}
