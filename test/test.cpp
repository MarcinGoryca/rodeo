//#include "game1.h"

#include "Console.h"

using namespace std;
using namespace mona::core;
using namespace mona;

int main()
{
	unique_ptr<Console> console(new Console());

	console->run();

	console->exit();
	system("pause");
	return 0;
}


//int WINAPI WinMain(HINSTANCE h, HINSTANCE p, LPSTR w, int c)
//{
//	unique_ptr<Game1> game1(new Game1(L"Game1"));
//	game1->create();
//	game1->onInit();
//	game1->run();
//	return 0;
//}
//
//void mona::controllers::EventController::getUserInput()
//{
//
//}