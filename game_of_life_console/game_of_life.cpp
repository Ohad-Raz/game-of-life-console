#include "game_of_life.h"
#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

bool game_of_life::random_value()
{
	return rand() % 4 == 0;
}

bool game_of_life::cell_taken(int i, int j)
{

	if (0 <= i and i < ROWS)
	{
		if (0 <= j and j < COLS)
		{
			return _generation[i][j];

		}
	}



	return false;
}

game_of_life::game_of_life()
{
	srand(time(nullptr));

	for (int row = 0; row < ROWS; row++)
	{

		for (int col = 0; col < COLS; col++)
		{
			_generation[row][col] = random_value();

		}



	}
}

void game_of_life::next_generation()
{

	for (int row = 0; row < ROWS; row++)
	{


		for (int col = 0; col < COLS; col++)
		{
			int counter = 0;

			for (int i_row = -1; i_row <= 1; i_row++)
			{
				for (int j_col = -1; j_col <= 1; j_col++)
				{
					if (i_row == 0 and j_col == 0)
					{
						continue;
					}
					else if (cell_taken(row + i_row, col + j_col))
					{
						counter++;
					}
				}
			}
			if (_generation[row][col])
			{
				if (counter == 2 or counter == 3)
				{
					_next_generation[row][col] = true;

				}
				else
				{
					_next_generation[row][col] = false;

				}
			}
			else
			{



				if (counter == 3)
				{
					_next_generation[row][col] = true;
				}
				else
				{
					_next_generation[row][col] = false;
				}
			}
		}
	}

	for (int row = 0; row < ROWS; row++)
		for (int col = 0; col < COLS; col++)
			_generation[row][col] = _next_generation[row][col];


}

void game_of_life::draw()
{
	system("cls");//I added for clearing the grid
	for (int row = 0; row < ROWS; row++)
	{


		for (int col = 0; col < COLS; col++)
		{

			if (_generation[row][col])
			{
				cout << " 0 ";
			}
			else
			{
				cout << " . ";

			}

		}
		cout << endl;


		
	}
	Sleep(500);//added delay

}
