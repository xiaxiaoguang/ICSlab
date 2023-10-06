/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 Emancio Light 
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
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitXnor - ~(x^y) using only ~ and | 
 *   Example: bitXnor(6, -5) = 2
 *   Legal ops: ~ |
 *   Max ops: 7
 *   Rating: 1
 */
int bitXnor(int x, int y) {
  return ~(x|y)|(~((~x)|(~y)));
}
/* 
 * bitConditional - x ? y : z for each bit respectively
 *   Example: bitConditional(0b00110011, 0b01010101, 0b00001111) = 0b00011101
 *   Legal ops: & | ^ ~
 *   Max ops: 4
 *   Rating: 1
 */
int bitConditional(int x, int y, int z) {
  return (x&y)|(~x&z);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 16
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  // int b0 = ((x & (0x000000FF<<n))>>n)<<m | (~((0x000000FF)<<m));
  // int b1 = ((x & (0x000000FF<<m))>>m)<<n | (~((0x000000FF)<<m));
  int n1 = (n<<3);
  int m1 = (m<<3);

  int a0 = ((x >> n1) & 0x000000FF);
  int a1 = ((x >> m1) & 0x000000FF);

  int c = a0 ^ a1;
  return x ^ (c<<n1) ^ (c<<m1);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int logicalShift(int x, int n) {
  int a = ((1<<31) & x);
  return (x >> n) ^ ((a >> n) << 1);
}
/* 
 * cleanConsecutive1 - change any consecutive 1 to zeros in the binary form of x.
 *   Consecutive 1 means a set of 1 that contains more than one 1.
 *   Examples cleanConsecutive1(0x10) = 0x10
 *            cleanConsecutive1(0xF0) = 0x0
 *            cleanConsecutive1(0xFFFF0001) = 0x1
 *            cleanConsecutive1(0x4F4F4F4F) = 0x40404040
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 4
 */
int cleanConsecutive1(int x){
  int tmp = x&(x<<1);
  return x^(tmp|(tmp>>1));
}
/*
 * leftBitCount - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x) {
  int y = x^(~0);
  int ob1 = ~((0x000000FF) + (0x000000FF << 8));
  int ob2 = 0x000000FF << 24;
  int ob3 = 0x0000000F << 28;
  int ob4 = 3 << 30;
  int ob5 = 1 << 31;
  // printf("%x %x %x %x %x %x\n",y,ob1,ob2,ob3,ob4,ob5);
  int ans=(!(y&ob1))<<4;//0xFFFF0000
  ans += (!(y&(ob2>>ans)))<<3;//0xFF000000
  ans += (!(y&(ob3>>ans)))<<2;
  ans += (!(y&(ob4>>ans)))<<1;
  ans += (!(y&(ob5>>ans)));
  ans += (!(y&(ob5>>ans)));
  return ans;
}
/* 
 * counter1To5 - return 1 + x if x < 5, return 1 otherwise, we ensure that 1<=x<=5
 *   Examples counter1To5(2) = 3,  counter1To5(5) = 1
 *   Legal ops: ~ & ! | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int counter1To5(int x) {
  int y = x + 1;
  int op = (((x & 1) & ((x & 4) >> 2))<<31)>>31;
  // if equal 0xFFFFFFFF ,then is 5 else is 0
  return  y + (~4 & op);
}
/* 
 * sameSign - return 1 if x and y have same sign, and 0 otherwise
 *   Examples sameSign(0x12345678, 0) = 1, sameSign(0xFFFFFFFF,0x1) = 0
 *   Legal ops: ! ~ & ! ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int sameSign(int x, int y) {
  int op = (x ^ y) >> 31;// x y dont have ,then is 0xFFFFFFFF else is 0
  return 1 + ((~0) & op);
}
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
// 715827882 * 3 = 2147483646
// -715827882 * 3 = -2147483646
// <-715827882 = -2147483647
// >=715827883 = 2147483647
  // int ng = (x & (0x80000000));
  // int a = 715827883;
  // int b0  = (a + (~x));
  // /*
  //   小于0,说明需要!
  // */
  // int ng1 = (b0 & (0x80000000));
  // int psE = (ng1) >> 31;// 如果确实，则pse为1，否则
  // int pos = (psE & 2147483647) | ((x + x + x) & 2147483647);// 防止加爆了
  // int b = 715827882;
  // int b1 = (x + b);// 如果为正说明可以,为负数就溢出
  // int ng2 = (b1 & (0x80000000));
  // int ngE = ng2 >> 31;//要溢出则为111111，否则为0
  // int neg = (ngE & (-2147483648)) | ((~ngE) & (x + x + x));// 这个无所谓吧
  // int qwq = (ng >> 31);
  // int ans = (qwq & neg) | ((~qwq) & pos);
  int y = x + x;
  int ans = y + x;
  int op = ((x ^ y) | (y ^ ans)) >> 31;
  int yichu = (x >> 31) ^ (~(1 << 31));
  return (op & yichu) + ((~op) & ans);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  int b0 = ~x + y + 1;
  int os = (1 << 31);
  int ng = (b0 & os) >> 31;
  int b1 = !((x & os) & (y ^ os));// x是负数而且y是正数，则有可能溢出，我们特判一下
  int b2 = !!((x ^ os) & (y & os));// x是正数，y是负数
  return (1 & ng & b1) | b2;
}

/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */

int subOK(int x, int y) {
    int sub = x + (~y) + 1;
    int ofc = ((x ^ y) & (x ^ sub)) >> 31;
    return !ofc;
}
/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x)
{
  int t1 = x>>3;
  int t2 = x&7;
  int a = t1 + t1 + t1 + t1 + t1;
  int b = (t2 + t2 + t2 + t2 + t2) >> 3;
  int o = ((!!((x>>31) & t2)) << 31) >> 31;// if is 0,then is 1
  return a + b + (1 & o);
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */


unsigned float_half(unsigned uf){
  unsigned int signBit = (1 << 31) & uf;
  unsigned int mantissa = 8388607 & uf;
  unsigned int tmp = mantissa;
  unsigned int mask = (0xFF << 23);
  unsigned int exponent = (uf & mask);
  // printf("%d %d %d\n",signBit,exponent,mantissa);
  exponent >>= 23;
  if(exponent == 0xFF)return uf;
  if(exponent>1){
    exponent-=1;
  }else {
    if(exponent){exponent -- ;mantissa |= (1<<23);}
    mantissa = ((mantissa+1) >> 1);
    if((mantissa & 1) && (tmp & 1))mantissa--;
    // if(exponent){exponent-=1,mantissa |= (1<<22);}
  }
  // printf("%d %d %d\n",signBit,exponent,mantissa);

  exponent <<= 23;
  return signBit | exponent | mantissa;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */

unsigned float_i2f(int x){
  int sign = x & 0x80000000;
  int mantissa;
  int exponent;
  int t1 = 1;
  if(x == -2147483648)return 0xcf000000;
  if(!x)return x;
  if(sign)x = -x;
  while(x >> t1)++t1;
  t1 -= 1;  
  x -= (1<<t1);  // 规格数有1
  exponent = 127 + t1;
  if(t1<=23){
    mantissa = x << (23-t1);
  }else {
    mantissa = x >> (t1-23);
    // for(int i=31;i>=0;--i){
    //   printf("%d",((x >> (t1-23))>>i)&1);
    //   if(i % 4==0)printf(" ");
    // }    
    // puts("");
    t1 = 1 << (t1-24);
    // printf("%d %d\n",x & t1,x&(t1-1));
    if(x&t1){
    // 四舍五入 + 向 偶数 舍入
      if(x & (t1 - 1))mantissa ++;
      else if((x >> 1) & t1)mantissa ++;
    }
    if(mantissa == 8388608){
      mantissa = 0;
      exponent ++;
    }
  }
  // printf("%d %d %d?\n",t1,exponent,mantissa);
  return sign|(exponent<<23)|mantissa;
}



/* 
 * float64_f2i - Return bit-level equivalent of expression (int) f
 *   for 64 bit floating point argument f.
 *   Argument is passed as two unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   double-precision floating point value.
 *   Notice: uf1 contains the lower part of the f64 f
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 20
 *   Rating: 4
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
  int sign = uf2 & 0x80000000u;
  int exponent = (uf2 & 0x7ff00000u) >> 20;
  unsigned mantissa = ((uf2 & 0x000fffff) << 11);
  // show(uf1);
  // show(exponent);
  // show(mantissa);
  mantissa +=  ((uf1 & 0xffc00000) >> 21);
  // show(mantissa);
  // printf("%d %d %u %u\n",sign,exponent,uf1,uf2);
  if(exponent < 1023)return 0;
  if(exponent >= 1054)return 0x80000000u;
  mantissa ^= 0x80000000u;
  mantissa >>= (1054 - exponent);
  if(sign)mantissa = -mantissa;
  return mantissa;
}
/* 
 * float_negpwr2 - Return bit-level equivalent of the expression 2.0^-x
 *   (2.0 raised to the power -x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^-x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 20 
 *   Rating: 4
 */
unsigned float_negpwr2(int x) {
  int exponent = 127 - x;
  int mantissa = 0;  
  if(x < -127)return 0x7F800000;
  if(x >= 150)return 0;
  if(exponent <= 0){
    mantissa = 1 << (22 + exponent);
    exponent = 0;
  }
  return exponent << 23 | mantissa;
}