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
//--------------------------------------------------------------------------
//	RandomNumberGenerator.h
//
//	!IMPORTANT NOTES!
//	Code comes from "Game Coding Complete" by Mike McShaffry
//	RNG Core name: Mersenne Twister by Takuji Nishimura and Makoto Matsumoto
//	Usage:
//	CRandom r;
//	r.Randomize();
//	unsigned int a = r.Random(1000) //returns a number from 0 - 999
//--------------------------------------------------------------------------
//*/
//#ifndef LAURA_TOOLS_RANDOMNUMBERGENERATOR_H_
//#define LAURA_TOOLS_RANDOMNUMBERGENERATOR_H_
//
//#define CMATH_N 624
//#define CMATH_M 397
//#define CMATH_MATRIX_A 0x9908b0df /* constant vector a */
//#define CMATH_UPPER_MASK 0x80000000 /* most significant w-r bits */
//#define CMATH_LOWER_MASK 0x7fffffff /* least significant r bits */
//
//#define CMATH_TEMPERING_MASK_B 0x9d2c5680
//#define CMATH_TEMPERING_MASK_C 0xefc60000
//#define CMATH_TEMPERING_SHIFT_U(y) (y >> 11)
//#define CMATH_TEMPERING_SHIFT_S(y) (y << 7)
//#define CMATH_TEMPERING_SHIFT_T(y) (y << 15)
//#define CMATH_TEMPERING_SHIFT_L(y) (y >> 18)
//
//namespace laura
//{
//	namespace tools
//	{
//		class CRandom
//		{
//		public:
//			CRandom()
//				:_seed(1), _mti(CMATH_N + 1) {}
//
//			// Returns number from 0 to n (excluding n)	
//			unsigned int random(unsigned int n);
//			void randomize();
//
//			void setRandomSeed(unsigned int n);
//			unsigned int getRandomSeed() { return _seed; }
//		private:
//			unsigned int _seed;
//			unsigned long _mt[CMATH_N];
//
//			// mti == N+1 (mt[N] is not initialized)
//			int _mti;
//		};
//	}
//}
//#endif