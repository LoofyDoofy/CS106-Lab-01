#include <stdio.h>

/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 x^y = x|y & ~(x&y)
     = ~(~x & ~y) & ~(x&y)
 */
int bitXor(int x, int y)
{
    return ~(~x & ~y) & ~(x&y);
}

int test_bitXor(int x, int y)
{
    return x ^ y;
}

int main(void)
{
    int x = 1;
    int y = 1;
    printf("expected: %x\n", bitXor(x, y));
    printf("actual  : %x\n", test_bitXor(x, y));
}
