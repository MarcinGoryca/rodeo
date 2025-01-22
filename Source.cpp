/*
#include "rodeo.h"
#include <tchar.h>

int WINAPI _tWinMain(HINSTANCE h, HINSTANCE p, LPTSTR l, int c)
{
	return 0;
}
*/

#include "rodeo.h"

int main() {

	std::cout << rodeo::core::PROJECT_NAME << std::endl;

	rodeo::tools::CRandom rng;
	rng.randomize();

	int x = rng.random(3);

	std::cout << x << std::endl;

	return 0;
}