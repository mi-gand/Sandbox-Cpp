#include <iostream>
#include <vector>

const int lines = 3;
const int columns = 3;
bool checkWin(char gameBoard[lines][columns], char symbol);


int main()
{
	setlocale(LC_ALL, "ru");
	char board[lines][columns]
	{
		{'-','-','-'},
		{'-','-','-'},
		{'-','-','-'},
	};
	bool win{ 0 };
	int count = 1;

	do
	{
		char walking{ 'Z' };
		if (count % 2 == 0) walking = 'O';
		else walking = 'X';
		std::cout << "Ходит " << walking << ".Введите позицию по вериткали и горизонтали: ";
		int linesInput{ -1 };
		int columnsInput{ -1 };
		std::cin >> linesInput >> columnsInput;
		int indexLinesInput = linesInput - 1;
		int indexColumnsInput = columnsInput - 1;
		if ((linesInput > 3 or linesInput < 1) or (columnsInput > 3 or columnsInput < 1) or board[indexLinesInput][indexColumnsInput] != '-')
		{
			std::cout << "Неправильные координаты!" << std::endl;
			continue;
		}
		board[indexLinesInput][indexColumnsInput] = walking;
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				std::cout << board[i][j];
			}
			std::cout << std::endl;
		}
		if (walking == 'X')
		{
			if (checkWin(board, walking))
			{
				std::cout << "Победил " << walking;
				win = true;
			}
		}
		if (walking == 'O')
		{
			if (checkWin(board, walking))
			{
				std::cout << "Победил " << walking;
				win = true;
			}
		}
		count++;
		if (count == 9)
		{
			std::cout << "Ничья";
			win = true;
		}

	} while (!win);

}

bool checkWin(char gameBoard[lines][columns], char symbol)
{
	int win = 0;
	if (gameBoard[0][0] == symbol and gameBoard[0][1] == symbol and gameBoard[0][2] == symbol) win++;
	if (gameBoard[1][0] == symbol and gameBoard[1][1] == symbol and gameBoard[1][2] == symbol) win++;
	if (gameBoard[2][0] == symbol and gameBoard[2][1] == symbol and gameBoard[2][2] == symbol) win++;

	if (gameBoard[0][0] == symbol and gameBoard[1][0] == symbol and gameBoard[2][0] == symbol) win++;
	if (gameBoard[0][1] == symbol and gameBoard[1][1] == symbol and gameBoard[2][1] == symbol) win++;
	if (gameBoard[0][2] == symbol and gameBoard[1][2] == symbol and gameBoard[2][2] == symbol) win++;

	if (gameBoard[0][0] == symbol and gameBoard[1][1] == symbol and gameBoard[2][2] == symbol) win++;
	if (gameBoard[0][2] == symbol and gameBoard[1][1] == symbol and gameBoard[2][0] == symbol) win++;
	if (win > 0) return true;
	else return false;
}