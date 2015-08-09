/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "math\mathsystem.h"

namespace mg
{
namespace math
{
void MathSystem::runGenerator()
{
    random_number_.randomize();
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
    buildSinusTable(sinus_table_);
    buildCosinusTable(cosinus_table_);

    runGenerator();
}
}    // end of math namespace
}    // end of mg namespace