/* 
 * CSE 351 HW1 (Data Lab )
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to this homework by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   Use the dlc compiler to check that your solutions conform
 *   to the coding rules.
 */


#endif
// Rating: 1
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  int z = ~((~x)|(~y));
  return z;
  //按位运算，列出真值表，进行拼凑
  //具体这里是德摩根律，析取的否定
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  //根据真值表和与或非特点进行拼接
  int z = (~(x & y))&(~((~x) & (~y)));
  return z;
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 * and the rest set to 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  // x = 0000 0000 0100 1001
  int x = 73;
  // x = 0100 1001 0000 0000
  x = x << 8;
  // x += 0000 0000 0010 0000
  // x = 0100 1001 0010 0000
  x = x + 36;
  // x = 0010 0000 0000 0000
  x = x << 8;
  // x += 0000 0000 1001 0010
  // x = 0010 0000 1001 0010
  x = x + 146;
  // x = 1001 0010 0000 0000
  x = x << 8;
  // x = 1001 0010 0100 1001
  x = x + 73;
 
  return x;
}
// Rating: 2
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  //when n == 3
  //valid positive x: 0 ~ 3, can be check by !(x >> 2)
  //valid negative x: -1 ~ -4, negate and substract 1, gets range: 0 ~ 3, same as positive
  //so valid negative can be check by !((~x + 1 + (-1)) >> 2)
  //then using sign to combine the two condition
  int ns = !(x >> 31);
  int l = n + (~1 + 1);
  int z = ((!(x >> l)) & ns) | ((!((~x) >> l)) & !ns);
  return z;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  int s = 0;
  //x >> 31 makes 0(x>=0) or -1(x<0)
  //|x makes 1(x>=0) or -1(x<0)
  //!x gets 0(x != 0) or 1(x == 0)
  //^(!x) makes 1(x>0) or 0(x=0) or -1(x<0)
  s = ((x >> 31) | 1) ^ (!x);
  return s;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  //n << 3 means n * 8, gets the bit to move left
  //move the nth byte to the 0th byte
  //& 255 mask out higher bytes
  int z = (x >> (n << 3)) & 255;
  return z;
}
// Rating: 3
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  // x >> n : arithmetic shift
  // & mask out high n bits
  // (((~1 + 1) << (~n + 32)) << 1) is the ~ of mask, and it equals ((~1 + 1) << (32 + ~n + 1)), (~1 + 1) is -1(all 1), (32 + ~n +1) is (32 - n)
  // ((~1 + 1) << (32 + ~n + 1)) is writted into (((~1 + 1) << (~n + 32)) << 1) becasue when n equals 32, ((~1 + 1) << (32 + ~n + 1)) return -1 but 0 (<< works from 0 to 31 but not 32)
  int z = (x >> n) & (~(((~1 + 1) << (~n + 32)) << 1));
  return z;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  int sx = x >> 31; //sign of x
  int sy = y >> 31; //sign of y
  int sxpy = (x + y) >> 31; //sign of x + y
  //two level
  //level 1: x, y have same sign?
  //level 2: x+y, x have same sign? 
  //combine the 2 level and use the feature of the bits op result
  int z = ~((sx ^ sy) | (~(sx ^ sxpy))) + 1;
  return z;
}
// Rating: 4
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  //op(x) := (~(x >> 31) + 1)
  //if x is negative, op(x) is 1
  //if x is positive, -x is negative, op(-x) is 1
  //so if x is not 0, op(x) | op(-x) is 1
  //if x is 0, op(x) | op(-x) is 0
  //1 ^ 1 is 0, 0 ^ 0 is 1
  int z = ((~(x >> 31) + 1) | (~((~x + 1) >> 31) + 1)) ^ 1;
  return z;
}
// Extra Credit: Rating: 3
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int n = ~(!x) + 1;
  int j = (y & (~n)) | (z & n);

  return j; 
}
// Extra Credit: Rating: 4
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  //when x is power of 2, x & (x - 1) is 0, when x is not power of 2, x & (x -1) is not 0
  int p = !(x & (x + ~0));
  //make sure x is not 0
  int nz = !(!x);
  //make sure x is not negative
  int nn = !(x >> 31);
  return (p & nz & nn);
}
