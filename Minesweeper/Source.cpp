// MINESWEEPER

//** overlapping mines

#include <iostream>

using namespace std;

int i, j, R, C, NumMines, BoardSize, proxMine = 0, guess = 0, Z = 0;
char board[55][55];								// CONTAINS GAMEBOARD
int mines[2][100];								// CONTAINS COORDINATES OF MINES
char digits[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };  // CONVERT INT TO CHAR FOR DISPLAY

void setup()
{
	for (i = 1; i <= BoardSize; i++)        // SETUP THE SQUARES
		for (j = 1; j <= BoardSize; j++)
			board[i][j] = 'X';

	for (i = 1; i <= NumMines; i++) {         // SETUP MINE LOCATIONS
		mines[1][i] = rand() % BoardSize + 1;
		mines[2][i] = rand() % BoardSize + 1;
	}
}

void display()     // DISPLAYS THE BOARD
{
	cout << "\n    ";
	for (i = 1; i <= BoardSize; i++)
		cout << " " << i; cout << "\n";
	for (i = 1; i <= BoardSize; i++) {
		cout << "\n " << i << "  ";
		for (j = 1; j <= BoardSize; j++)
			cout << " " << board[i][j];
	}
}

void main()
{

	for (;;)
	{

		cout << "Choose board size (between 2 and 50): ";
		cin >> BoardSize;
		cout << "Choose number of mines (between 1 and 100): ";
		cin >> NumMines;

		setup();

		while (guess < (BoardSize * BoardSize) - NumMines)        // RUNS LOOP UNTIL GAME IS WON
		{
			display();

			proxMine = 0;

			cout << "\n\nChoose row: ";
			cin >> R;
			cout << "Choose column: ";
			cin >> C;

			for (i = 1; i <= NumMines; i++)
			{
				if ((R == mines[1][i]) && (C == mines[2][i])) {      // EVALUATE IF MINE IS HIT
					cout << "\nBOOM! Game Over\n\n Play again? (1) Yes (2) No: ";
					cin >> Z;
					if (Z == 1)
						goto replay;
					else
						goto stop;
				}
				if (((abs(R - mines[1][i])) < 2) && ((abs(C - mines[2][i])) < 2))     // COUNT NEARBY MINES
					proxMine++;

				board[R][C] = digits[proxMine];

			}
			guess++;														// LOOP COUNTER
		}

		cout << "\n\nCongratulations, you win!\n\n Play again? (1) Yes (2) No: ";
		cin >> Z;
		if (Z != 1)
			break;

	replay: cout << "\nReplaying\n\n";

	}

stop: cout << "\nExiting\n\n";

	return;
}