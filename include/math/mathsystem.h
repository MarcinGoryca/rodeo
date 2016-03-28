/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_MATH_MATHSYSTEM_H_
#define MG_MATH_MATHSYSTEM_H_

#ifndef MG_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MG_MATH_MATHTOOLS_H_
#include "math\mathtools.h"
#endif

#ifndef MG_TOOLS_RANDOMNUMBERGENERATOR_H_
#include "tools\randomnumbergenerator.h"
#endif

namespace mg
{
namespace math
{
class MathSystem : public mg::core::Singleton<MathSystem>
{
public:
    MathSystem()
    {
        init();
    }

    ~MathSystem(){}

    // Gets the random number
    mg::tools::CRandom getRandomNumber() const { return _random_number; }

    // Gets specified member of sinus table
    // Returns float value of specified index from sinus table
    float getSinusTable(int index) const { return _sinus_table[index]; }

    // Gets specified member of cosinus table
    // Returns float value of specified index from cosinus table
    float getCosinusTable(int index) const { return _cosinus_table[index]; }

private:
	// Random Number
	mg::tools::CRandom _random_number;

	// Full Sinus Table
	float _sinus_table[mg::core::MG_FULL_CIRCLE];

	// Full Sosinus Table
	float _cosinus_table[mg::core::MG_FULL_CIRCLE];
    // Runs Random Number Generator (Mersenne Twister)
    void runGenerator();
    void init();


};
}    // end of math namespace
}    // end of mg namespace
#endif    //MG_MATH_MATHSYSTEM_H_
