/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include <time.h>
#include "tools\randomnumbergenerator.h"

namespace mg
{
namespace tools
{
unsigned int CRandom::random(unsigned int n)
{
    unsigned long y;

    static unsigned long mag01[2] = { 0x0, CMATH_MATRIX_A };

    if(n == 0)
        return 0;
    /* mag01[x] = x * MATRIX_A for x=0,1 */

    if (mti_ >= CMATH_N) { /* generate N words at one time */
        int kk;

        if (mti_ == CMATH_N+1)   /* if sgenrand() has not been called, */
            setRandomSeed(4357); /* a default initial seed is used   */

        for (kk=0;kk<CMATH_N-CMATH_M;kk++) {
            y = (mt_[kk]&CMATH_UPPER_MASK)|(mt_[kk+1]&CMATH_LOWER_MASK);
            mt_[kk] = mt_[kk+CMATH_M] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        for (;kk<CMATH_N-1;kk++) {
            y = (mt_[kk]&CMATH_UPPER_MASK)|(mt_[kk+1]&CMATH_LOWER_MASK);
            mt_[kk] = mt_[kk+(CMATH_M-CMATH_N)] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        y = (mt_[CMATH_N-1]&CMATH_UPPER_MASK)|(mt_[0]&CMATH_LOWER_MASK);
        mt_[CMATH_N-1] = mt_[CMATH_M-1] ^ (y >> 1) ^ mag01[y & 0x1];

        mti_ = 0;
    }

    y = mt_[mti_++];
    y ^= CMATH_TEMPERING_SHIFT_U(y);
    y ^= CMATH_TEMPERING_SHIFT_S(y) & CMATH_TEMPERING_MASK_B;
    y ^= CMATH_TEMPERING_SHIFT_T(y) & CMATH_TEMPERING_MASK_C;
    y ^= CMATH_TEMPERING_SHIFT_L(y);

    return (y%n);
}


void CRandom::setRandomSeed(unsigned int n)
{
   /* setting initial seeds to mt[N] using         */
   /* the generator Line 25 of Table 1 in          */
   /* [KNUTH 1981, The Art of Computer Programming */
   /*    Vol. 2 (2nd Ed.), pp102]                  */
   mt_[0]= n & 0xffffffff;
   for (mti_=1; mti_<CMATH_N; mti_++)
     mt_[mti_] = (69069 * mt_[mti_-1]) & 0xffffffff;

   seed_ = n;
}


void CRandom::randomize()
{
   setRandomSeed(static_cast<unsigned int>(time(NULL)));
}
}    // end of tools namespace
}    // end of mg namespace