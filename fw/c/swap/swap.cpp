//  FOR GIVEN TWO POSITION IN AN INTEGER SWAP THE BITS
//  ==================================================
//
//  EXAMPLE FOR INPUT VALUE 76 (0x4C), IN BINARY 0100-1100
//  IF GIVEN POSITION i=2 AND j=5 (3rd and 6th bits from right)
//  AFTER SWAP IT WILL BE 104 (0x28), IN BINARY 0110-1000


#include <iostream>
#include <bitset>

using namespace std;

// Function to swap bits at position 'i' and 'j' in integer 'n'
int swap(int n, int i, int j)
{
    // implement swap function here!

    return n;
}

int main(void)
{
    int n = 76;
    int i = 2, j = 5;    // swap 3rd and 6th bit from the right

    cout << n << " in binary is " << bitset<8>(n) << endl;
    n = swap (n, i, j);
    cout << n << " in binary is " << bitset<8>(n) << endl;

    return 0;
}
