#include <iostream>
#include <vector>

int main()
{
	std::vector <int> _array(20);
	int curpos = 0;
	int input = -3;
	std::cout << "Enter numbers of array: \n";
	while (input != -2)
	{
		std::cin >> input;
		if (input == -1)
		{
			for (int i = curpos; i < _array.size(); i++)
			{
				std::cout << _array[i] << " ";
			}
			for (int i = 0; i < curpos; i++)
			{
				std::cout << _array[i] << " ";
			}
			std::cout << std::endl;
		}
		else
		{
			_array[curpos] = input;
			curpos++;
			if (curpos == 20) curpos = 0;
		}
	}
	std::cout << "END";
	return 0;
}