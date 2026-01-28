#include <stdio.h>

/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 // short: 0000 0000 0000 0000
 // TMin:  1000 0000 0000 0000
 // (-1):  1111 1111 1111 1111
 // TMax:  0111 1111 1111 1111

 //  int: 0000 0000 0000 0000 0000 0000 0000 0000
 // TMin: 1000 0000 0000 0000 0000 0000 0000 0000
 // (-1): 1111 1111 1111 1111 1111 1111 1111 1111
 // TMax: 0111 1111 1111 1111 1111 1111 1111 1111
 // (-1): 1111 1111 1111 1111 1111 1111 1111 1111
 // >>15: 1111 1111 1111 1111 1000 0000 0000 0000
 // >>16: 1111 1111 1111 1111 
 //     :                     1000 0000 0000 0000
 */
int fitsShort(int x)
{
    return !((x>>15) ^ (x>>16));
}

int test_fitsShort(int x)
{
    short int sx = (short int) x;
    return x == sx;
}

int main(void)
{
    int x = 0xFFFF9000;
    printf("expected: %x\n", fitsShort(x));
    printf("actual  : %x\n", test_fitsShort(x));
}
