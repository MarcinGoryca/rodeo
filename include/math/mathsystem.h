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
    mg::tools::CRandom getRandomNumber() const { return random_number_; }

    // Gets specified member of sinus table
    // Returns float value of specified index from sinus table
    float getSinusTable(int index) const { return sinus_table_[index]; }

    // Gets specified member of cosinus table
    // Returns float value of specified index from cosinus table
    float getCosinusTable(int index) const { return cosinus_table_[index]; }

private:
    // Runs Random Number Generator (Mersenne Twister)
    void runGenerator();
    void init();

    // Random Number
    mg::tools::CRandom random_number_;

    // Full Sinus Table
    float sinus_table_[mg::core::MG_FULL_CIRCLE];

    // Full Sosinus Table
    float cosinus_table_[mg::core::MG_FULL_CIRCLE];
};
}    // end of math namespace
}    // end of mg namespace
#endif    //MG_MATH_MATHSYSTEM_H_
