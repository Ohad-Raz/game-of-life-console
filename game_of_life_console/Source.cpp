#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
#include <windows.h>

using namespace std;

int main() {
	game_of_life the_game;

	bool again;
	do {
		the_game.draw();

		the_game.next_generation();

		cout <<"\n"<< "Again (1/0): ";

		cin >> again;
	} while (again);

	return 0;
}