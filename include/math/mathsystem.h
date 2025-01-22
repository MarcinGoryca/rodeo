/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2010 - ... Marcin Goryca
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
#ifndef RODEO_MATH_MATHSYSTEM_H_
#define RODEO_MATH_MATHSYSTEM_H_

#ifndef RODEO_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef RODEO_MATH_MATHTOOLS_H_
#include "math\mathtools.h"
#endif

#ifndef RODEO_TOOLS_RNG_H_
#include "tools\rng.h"
#endif

namespace rodeo
{
namespace math
{
class MathSystem : public rodeo::core::Singleton<MathSystem>
{
public:
    MathSystem()
    {
        init();
    }

    ~MathSystem(){}

    // Gets the random number
    //rodeo::tools::CRandom getRandomNumber() const { return _random_number; }

    // Gets specified member of sinus table
    // Returns float value of specified index from sinus table
    float getSinusTable(int index) const { return _sinus_table[index]; }

    // Gets specified member of cosinus table
    // Returns float value of specified index from cosinus table
    float getCosinusTable(int index) const { return _cosinus_table[index]; }

private:
	// Random Number
	//rodeo::tools::CRandom _random_number;

	// Full Sinus Table
	float _sinus_table[rodeo::core::RODEO_FULL_CIRCLE];

	// Full Cosinus Table
	float _cosinus_table[rodeo::core::RODEO_FULL_CIRCLE];
    // Runs Random Number Generator (Mersenne Twister)
    void runGenerator();
    void init();


};
}    // end of math namespace
}    // end of rodeo namespace
#endif    //RODEO_MATH_MATHSYSTEM_H_
