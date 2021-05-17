#include <iostream>
#include <vector>
#include <string>
#include <string_view>

std::string mailchack(std::string);

int main()
{	
	setlocale(LC_ALL, "ru" );
	std::string mail{};
	std::cout << "Введите свою почту: ";
	std::getline(std::cin, mail);
	std::cout << mailchack(mail);

	return 0;
}

std::string mailchack(std::string mail)
{
	std::string_view partRight{ mail };
	std::string_view partLeft{ mail };
	int devisor = mail.find('@');						//место расположения @
	bool commonCond = true;
	if (devisor > std::size(mail))
	{
		commonCond = false;
	}
	else
	{
		partRight.remove_prefix(devisor + 1);
		partLeft.remove_suffix(std::size(partLeft) - devisor);
	}
	bool leftCond = true;								//Проверяем левую часть почты
	if (partLeft.length() > 64 and partLeft.length() < 1) leftCond = false;
	for (int index = 0; index < partLeft.length(); ++index)
	{
		if ((partLeft[index] >= 65 and partLeft[index] <= 90) or (partLeft[index] >= 97 and partLeft[index] <= 122)
			or (partLeft[index] >= 48 and partLeft[index] <= 57) or (partLeft[index] == '-') or (partLeft[index] == '.')
			or (partLeft[index] == '!') or (partLeft[index] == '*') or (partLeft[index] == '+') or (partLeft[index] == '-')
			or (partLeft[index] == '/') or (partLeft[index] == '=') or (partLeft[index] == '?') or (partLeft[index] == '^')
			or (partLeft[index] == '_') or (partLeft[index] == '`') or (partLeft[index] == '{') or (partLeft[index] == '|')
			or (partLeft[index] == '}') or (partLeft[index] == '~'))
			{
				leftCond = true;
			}
		else leftCond = false;
	}
	for (int index = 0; index < partLeft.length(); ++index)
	{
		if (partLeft[0] == '.' or partLeft[partLeft.length() - 1] == '.')
		{
			leftCond = false;
			break;
		}
		if (partLeft[index] == '.' and partLeft[index + 1] == '.')
		{
			leftCond = false;
			break;
		}
	}
	bool rightCond = true;									//проверяем правую часть почты
	{
		if (partRight.length() > 64 and partRight.length() < 1) rightCond = false;
		for (int index = 0; index < partRight.length(); ++index)
		{
			if ((partRight[index] >= 65 and partRight[index] <= 90) or (partRight[index] >= 97 and partRight[index] <= 122)
				or (partRight[index] >= 48 and partRight[index] <= 57) or (partRight[index] == '-') or (partRight[index] == '.'))

			{
				rightCond = true;
			}
			else rightCond = false;
		}
		for (int index = 0; index < partRight.length(); ++index)
		{
			if (partRight[0] == '.' or partRight[partRight.length() - 1] == '.')
			{
				rightCond = false;
				break;
			}
			if (partRight[index] == '.' and partRight[index + 1] == '.')
			{
				rightCond = false;
				break;
			}
		}
		if (rightCond and leftCond and commonCond)			//если правая, левая часть и общие условия верны, то проходит
		{
			return "Yes";
		}
		else
		{
			return "No";
		}
	}
}
