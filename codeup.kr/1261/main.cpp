#include <iostream>

int main(int argc, char **argv)
{
	for(int i = 0; i < 10; i++)
	{
		int tmp;
		std::cin >> tmp;
		if(tmp % 5 == 0)
		{
			std::cout << tmp << std::endl;
			return 0;
		}
	}
	std::cout << "0" << std::endl;
	return 0;
}

