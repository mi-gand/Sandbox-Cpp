#include <iostream>
#include <string>

const int width = 3;
const int height = 3;
const int8_t Incorrect = 0;														//для исключений для управлением потоком (что неправильно, но тестирую exception)
const int16_t Nobody = 0;
const int32_t PetyaWin = 0;
const int64_t VasyaWin = 0;
void validSymbol(char gameBoard[height][width], bool& flagOut);					//проверка на валидные символы 'Х','О','.'. Если гуд, то Out флаг и цикл-проверка заканчивается.
bool checkWin(const char gameBoard[height][width], char symbol) throw(int8_t);	//проверка каждого на 8 возможных победных вариантов. Если больше одного, то Out инкоррект
void finalCheck(const char gameBoard[height][width], bool personWin1, bool personWin2, char Person1, char Person2) throw(...);

int main()
{
	setlocale(LC_ALL, "ru");
	char gameBoard[height][width] = { {} };
	bool flagValidSymbol{ 0 };

	do
	{
		std::cout << "Введите 3 строки с игровой доски без пробелов в формате:\n" << "XOX\n" << "X.O\n" << "X.." << std::endl;
		std::cout << "Ваш ввод:" << std::endl;
		std::cin >> gameBoard[0];
		std::cin >> gameBoard[1];
		std::cin >> gameBoard[2];
		validSymbol(gameBoard, flagValidSymbol);
	} while (!flagValidSymbol);

	try
	{
		char Petya = 'X';
		char Vasya = 'O';
		bool PetyaWin = checkWin(gameBoard, Petya);
		bool VasyaWin = checkWin(gameBoard, Vasya);
		finalCheck(gameBoard, PetyaWin, VasyaWin, Petya, Vasya);
	}
	catch (int8_t)
	{
		std::cout << "Incorrect";
	}
	catch (int16_t)
	{
		std::cout << "Nobody";
	}
	catch (int32_t)
	{
		std::cout << "PetyaWin";
	}
	catch (int64_t)
	{
		std::cout << "VasyaWin";
	}

	return 0;
}

void validSymbol(char gameBoard[height][width], bool& flagOut)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (gameBoard[i][j] == 'X' or gameBoard[i][j] == 'O' or gameBoard[i][j] == '.')
			{
				flagOut = true;
			}
			else
			{
				break;
			}
		}
		if (!flagOut) break;
	}
}

bool checkWin(const char gameBoard[height][width], char symbol)
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

	if (win > 1) throw Incorrect;
	if (win == 0) return false;
	if (win == 1) return true;
}

void finalCheck(const char gameBoard[height][width], bool personWin1, bool personWin2, char Person1, char Person2)
{
	if (personWin1 == 1 and personWin2 == 1) throw Incorrect;
	int countX_Petya1{ 0 };
	int countY_Vasya2{ 0 };
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (gameBoard[i][j] == Person1)	countX_Petya1++;
			if (gameBoard[i][j] == Person2)	countY_Vasya2++;
		}
		if (personWin1 and countY_Vasya2 >= countX_Petya1) throw Incorrect;
		if (personWin2 and countX_Petya1 >= countY_Vasya2) throw Incorrect;
		if (personWin1 == 0 and personWin2 == 0 and countX_Petya1 <= 5 and countY_Vasya2 <= 4) throw Nobody;
		if (personWin1 == 1) throw PetyaWin;
		if (personWin2 == 1) throw VasyaWin;
	}
}