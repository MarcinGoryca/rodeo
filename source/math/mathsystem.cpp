/*
----------------------------------------------
    mona Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "math\mathsystem.h"

namespace mona
{
namespace math
{
void MathSystem::runGenerator()
{
    _random_number.randomize();
}

/**
 * @remarks USE init() method instead
 */

//void MathCore::init(float* sinus, float* cosinus)
//{
//    buildSinusTable(sinus);
//    buildCosinusTable(cosinus);
//}

/**
 *
 */

void MathSystem::init()
{
    buildSinusTable(_sinus_table);
    buildCosinusTable(_cosinus_table);

    runGenerator();
}
}    // end of math namespace
}    // end of mona namespace