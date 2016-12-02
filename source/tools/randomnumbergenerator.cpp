/*
 | --------------------------------------------------------------------------------------------------
 |     Laura Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
 |
 |     Permission is hereby granted, free of charge,
 |     to any person obtaining a copy of this software
 |     and associated documentation files (the "Software"),
 |     to deal in the Software without restriction,
 |     including without limitation the rights to use,
 |     copy, modify, merge, publish, distribute, sublicense,
 |     and/or sell copies of the Software,
 |     and to permit persons to whom the Software is furnished to do so,
 |     subject to the following conditions:
 |
 |     The above copyright notice and this permission notice
 |     shall be included in all copies or substantial portions of the Software.
 |
 |     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 |     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 |     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 |     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 |     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 |     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 |     IN THE SOFTWARE.
 |---------------------------------------------------------------------------------------------------
 */
//#include <time.h>
//#include "tools\randomnumbergenerator.h"
//
//namespace laura
//{
//	namespace tools
//	{
//		unsigned int CRandom::random(unsigned int n)
//		{
//			unsigned long y;
//
//			static unsigned long mag01[2] = { 0x0, CMATH_MATRIX_A };
//
//			if (n == 0)
//				return 0;
//			/* mag01[x] = x * MATRIX_A for x=0,1 */
//
//			if (_mti >= CMATH_N) { /* generate N words at one time */
//				int kk;
//
//				if (_mti == CMATH_N + 1)   /* if sgenrand() has not been called, */
//					setRandomSeed(4357); /* a default initial seed is used   */
//
//				for (kk = 0; kk < CMATH_N - CMATH_M; kk++) {
//					y = (_mt[kk] & CMATH_UPPER_MASK) | (_mt[kk + 1] & CMATH_LOWER_MASK);
//					_mt[kk] = _mt[kk + CMATH_M] ^ (y >> 1) ^ mag01[y & 0x1];
//				}
//				for (; kk < CMATH_N - 1; kk++) {
//					y = (_mt[kk] & CMATH_UPPER_MASK) | (_mt[kk + 1] & CMATH_LOWER_MASK);
//					_mt[kk] = _mt[kk + (CMATH_M - CMATH_N)] ^ (y >> 1) ^ mag01[y & 0x1];
//				}
//				y = (_mt[CMATH_N - 1] & CMATH_UPPER_MASK) | (_mt[0] & CMATH_LOWER_MASK);
//				_mt[CMATH_N - 1] = _mt[CMATH_M - 1] ^ (y >> 1) ^ mag01[y & 0x1];
//
//				_mti = 0;
//			}
//
//			y = _mt[_mti++];
//			y ^= CMATH_TEMPERING_SHIFT_U(y);
//			y ^= CMATH_TEMPERING_SHIFT_S(y) & CMATH_TEMPERING_MASK_B;
//			y ^= CMATH_TEMPERING_SHIFT_T(y) & CMATH_TEMPERING_MASK_C;
//			y ^= CMATH_TEMPERING_SHIFT_L(y);
//
//			return (y%n);
//		}
//
//
//		void CRandom::setRandomSeed(unsigned int n)
//		{
//			/* setting initial seeds to mt[N] using         */
//			/* the generator Line 25 of Table 1 in          */
//			/* [KNUTH 1981, The Art of Computer Programming */
//			/*    Vol. 2 (2nd Ed.), pp102]                  */
//			_mt[0] = n & 0xffffffff;
//			for (_mti = 1; _mti < CMATH_N; _mti++)
//				_mt[_mti] = (69069 * _mt[_mti - 1]) & 0xffffffff;
//
//			_seed = n;
//		}
//
//
//		void CRandom::randomize()
//		{
//			setRandomSeed(static_cast<unsigned int>(time(NULL)));
//		}
//	}
//}