#include <iostream>
#include <string>
#include <string_view>
#include <vector>

std::vector<std::string_view> SplitString(const std::string_view line,
	const char delimiter);
bool validation(std::string ip, bool flagAllGood);
bool checkQuatersString(const std::vector<std::string_view>& array, bool &flagAllGood);
bool checkQuatersInt(int &part, bool& flagAllGood);

int main()
{
	setlocale(LC_ALL, "ru");
	std::string ip{};
	std::cout << "Введите свой IP: ";
	std::getline(std::cin, ip);
	bool flagAllGood = true;
	validation(ip, flagAllGood);

	if (validation(ip, flagAllGood)) std::cout << "Yes";
	else std::cout << "No";

	

}
bool validation(const std::string ip, bool flagAllGood)
{
	int dotCounter = 0;
	int charCounter = 0;
	for (int index = 0; index < std::size(ip); index++)
	{
		if (ip[index] == '.') dotCounter++;
		charCounter++;
		if (ip[index] >= '0' and ip[index] <= '9' or ip[index] == '.')
		{
			flagAllGood = true;
		}
		else return flagAllGood = false;

	}
	if (dotCounter not_eq 3 or charCounter > 15)
	{
		return flagAllGood = false;
	}
	std::string_view _ip = ip;
	char delimiter = '.';
	std::vector<std::string_view> array = SplitString(_ip, delimiter);

	if (checkQuatersString(array, flagAllGood)) flagAllGood = true;
	else return flagAllGood = false;


	int part1 = atoi((array.at(0).data()));
	int part2 = atoi((array.at(1).data()));
	int part3 = atoi((array.at(2).data()));
	int part4 = atoi((array.at(3).data()));

	checkQuatersInt(part1, flagAllGood);
	checkQuatersInt(part2, flagAllGood);
	checkQuatersInt(part3, flagAllGood);
	checkQuatersInt(part4, flagAllGood);

	return flagAllGood;
}
bool checkQuatersString(const std::vector<std::string_view> &array, bool &flagAllGood)
{
	for (std::string_view number : array)
	{
		if (number.empty()) {
			return false;
		}
		for (int i = 0; i < std::size(number) - 1; i++)
		{
			if((number[std::size(number)-1] == '.' and (number[std::size(number)-2] == '.'))
				or (number[std::size(number)-1] == '0' and (number[std::size(number) - 2] == '0')))
			{
				return flagAllGood = false;
			}
			if(number[i] == '.' and number[i + 1] == '.' or number[i] == '0' and number[i + 1] == '0')
			{
				return flagAllGood = false;
			}
			if (number[i] == '0' and number[i + 1] != '0')
			{
				return flagAllGood = false;
			}
		}
	}
	return flagAllGood;
}



bool checkQuatersInt(int &part, bool &flagAllGood)
{
	if (part > 255) return flagAllGood = false;;
}


std::vector<std::string_view> SplitString(const std::string_view line,
	const char delimiter) 
{
	std::vector<std::string_view> tokens;

	size_t begin = 0;
	while (begin < line.size()) 
	{
		const size_t end = line.find(delimiter, begin);
		tokens.push_back(line.substr(begin, end - begin));
		if (end == std::string_view::npos) {
			break;
		}
		begin = end + 1;
	}

	return tokens;
}

