#include <iostream>
#include <string>
#include <vector>

bool symbolValidation(std::string, bool, bool& signOut);		//ф-ция для первичной проверки корректности введенных данных и заодно выводит негативность числа(для себя потыкаться с ссылками)
std::vector<std::string> SplitString(const std::string line,
	const char delimiter);						//ф-ция для разбивания строки на целые числа и десятичные

int main()
{
	setlocale(LC_ALL, "ru");
	bool validationGross = false;				//флаг для первичной проверка корректности введенных данных
	std::string firstNumber{}, secondNumber{};
	bool negativeSign1{ false };				//флаги для проверки наличия знаков у 2 чисел
	bool negativeSign2{ false };

	do											//цикл для первичной проверка валидности введенных данных
	{
		std::cout << "Введите два числа: ";
		std::cin >> firstNumber >> secondNumber;

	} while (!(symbolValidation(firstNumber, validationGross, negativeSign1) and (symbolValidation(secondNumber, validationGross, negativeSign2))));

	int dotIndex1{};							//ищем где индекс точки и ставим флаг наличия точки
	bool flagDot1{ false };
	int dotIndex2{};
	bool flagDot2{ false };

	for (int i = 0; i < std::size(firstNumber); i++)
	{
		if (firstNumber[i] == '.')
		{
			dotIndex1 = i;
			flagDot1 = true;
			break;
		}
	}
	for (int i = 0; i < std::size(secondNumber); i++)
	{
		if (secondNumber[i] == '.')
		{
			dotIndex2 = i;
			flagDot2 = true;
			break;
		}
	}
	const char delimiter = '.';									//обозначаем разделитель и бьем каждую строку на 1 или 2 вектора
	int firstInteger{ 0 };
	int secondInteger{ 0 };

	std::vector <std::string> first_array = SplitString(firstNumber, delimiter);
	std::vector <std::string> second_array = SplitString(secondNumber, delimiter);

	firstInteger = atoi((first_array.at(0).data()));			//конвертируем первое значение контейнера в целое число
	secondInteger = atoi((second_array.at(0).data()));			//конвертируем второе значение контейнера в целое число

	try															//для того чтоб не писать ф-ции (и потыкаться в новый инструмент) вводим исключения
	{
		int More = 1;
		double Equal = 7.7;
		char Less = 'L';

		if (firstInteger > secondInteger) throw More;			//сначала сравниваем целые числа
		if (firstInteger < secondInteger) throw Less;
		if (firstInteger == secondInteger and std::size(first_array) == 1 and std::size(second_array) == 1) throw Equal;
		if (firstInteger == secondInteger)						//если целые равны, то переходим к сравнению десятичных чисел
		{
			if (std::size(first_array[1]) < std::size(second_array[1]))					//докидываю нули в конец, чтоб одинаковое количество значений было
			{
				int difference = std::size(second_array[1]) - std::size(first_array[1]);
				for (int i = 0; i < difference; i++)
				{
					first_array[1].push_back('0');
				}
			}
			for (int i = 0; i < std::size(first_array[1]); i++)
			{

				if (first_array[1][i] == second_array[1][i])
				{
					continue;
				}
				if (first_array[1][i] < second_array[1][i])
				{
					if (negativeSign1 and negativeSign2)
					{
						throw More;
					}
					throw Less;
				}
				else
				{
					if (negativeSign1 and negativeSign2)
					{
						throw Less;
					}
					throw More;
				}
			}
			throw Equal;
		}
	}
	catch (int)
	{
		std::cout << "More";
	}
	catch (char)
	{
		std::cout << "Less";
	}
	catch (double)
	{
		std::cout << "Equal";
	}
}
bool symbolValidation(std::string number, bool validation, bool& signOut)
{
	int dotCounter = 0;
	for (unsigned int index = 0; index < std::size(number); index++)
	{
		if (number[index] >= '0' and number[index] <= '9' or number[index] == '.' or number[0] == '-')
		{
			validation = true;
			if (number[0] == '-') signOut = true;
		}
		else return false;
		if (number[index] == '.') dotCounter++;
		if (dotCounter > 1) return false;
		if (number[number.size() - 1] == '.' or number[number.size() - 1] == '0') return false;
		if (number.find('.') > 1)
		{
			for (int i = 0; i < number.find('.') - 1; i++)
			{
				if (number[i] == '0' and number[i + 1] != 0) return false;
			}
		}
	}
	return true;
}

std::vector<std::string> SplitString(const std::string line,
	const char delimiter)
{
	std::vector<std::string> tokens;

	size_t begin = 0;
	while (begin < line.size()) {
		const size_t end = line.find(delimiter, begin);
		tokens.push_back(line.substr(begin, end - begin));
		if (end == std::string::npos) {
			break;
		}
		begin = end + 1;
	}
	return tokens;
}