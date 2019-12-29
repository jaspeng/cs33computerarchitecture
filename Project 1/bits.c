/* 
 * CS:APP Data Lab 
 * 
 * <Jasmine Peng. 004 939 829> 
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

You will provide your solution to the Data Lab by
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
   *ugroup AutomaticSwapRecoveryAndDelete
    autocmd!
    autocmd SwapExists * :let v:swapchoice = 'r' | let b:swapname = v:swapname 
    autocmd BufWinEnter * :if exists("b:swapname") | call delete(b:swapname) | unlet b:swapname | endif pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
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

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BiD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  //Assumption: x = Tmax
  //Following observation that Tmin = Tmax + 1 
  //Notice that Tmin + Tmax gives -1 (111111111..) 
  //However, we will also get this result if x = -1
  //To take care of this case, add !Tmin (equals 0 in all cases except when x = -1 
  //Finally, use ~ then ! to make sure we return true when result = -1
  int Tmin = x + 1; 
  int result = x + Tmin + (!Tmin);  
  return !(~result);
}
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
// order of applying the operations ~ | ~ (seems to work on cases I've looked at thus far) 
  int tempX = ~x; 
  int tempY = ~y;
  int result = (tempX | tempY); 
  return (~result); 
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
//left shift means that 0's will take place of bits
//right shift means that vacant bits will be filled with the leading value 
  x = x<<31; 
  x = x>>31;  
  return x; 
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
//5 has a binary value of 0101 (1's in the even spaces) 
//Use this as a template to construct a 32 bit representation of only 1's in even spaces
//Accomplish with shifting 
//Compare with our x value with & 
//Double !! will return 1 (true) if a 1 is in any even space
//and a 0 otherwise 
  int q = 0x55;
  int r = q + (q << 8);
  int s = r + (r << 16); 
  int result = x&s; 
  return !!result; 
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
//To approach this problem, we need to cover two bases (positive and negative) 
//We do this by applying taking x and converting x to its negative counterpart
//Only when x is zero will its sign bit be zero before and after conversion
//If x is any other value, we will get -1 (1111111111....). 
//Add 1 to the final value so that 0 becomes 1 (true) and -1 becomes 0 (false)
  int val = (( x>>31 ) | ((~x+1) >> 31)); 
  return val + 1;  
}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {
   int pow = (1 << n) + ~0;  
   int result = (x & pow);  
   int neg = ((x & (~result + 1)) >> 31);
   return result + (neg & ~pow); 
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) {
//Divide into two parts - multiply by five then divide by eight
//Shift to the left by 2 to multiply by 4 then add itself to
//achieve 5. To divide by 8 we can simply shift three spaces
//to the right. However, we need to take care of the negative case. 
//To do so we add 7 (2^w - 1) only when the integer passed in is negative
//prior to shifting.
  int multFive = ((x << 2) + x); 
  int sign = 7 & (x >> 31);
  return ((multFive + sign) >> 3); 
 
}
/* 
 * tc2sm - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: tc2sm(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 */
 int tc2sm(int x) {
//Preserve the bit containing the signed value 
//Knowing we only want to change negative values, utilize 
//the value of sign (-1 or 0) as the bench to determine
//if the int passed in must be changed. 
     int sign = x >> 31; 
     int signBit = sign << 31; 
     int flip = x ^ sign; 
     int addOne = ~sign + 1; 
     return signBit + flip + addOne;         
  } 
