#include <iostream>

void foo(bool** arr);

int main()
{
	bool** arr = new bool* [12];
	foo(arr);

	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void foo(bool** arr)
{
	for(int i = 0; i < 12; ++i)
	{
		arr[i] = new bool[12];
		for (int j = 0; j < 12; ++j)
		{
			arr[i][j] = 0;
		}
	}
}