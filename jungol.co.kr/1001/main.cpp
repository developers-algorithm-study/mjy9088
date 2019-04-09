#include <iostream>

int main(int argc, char **argv)
{
	int a, b;
	while(true)
	{
		std::cin >> a;
		std::cin >> b;
		if(a > 1000 || b > 4000)
		{
			std::cout << "INPUT ERROR!" << std::endl;
			continue;
		}
		if(a == 0 && b == 0)
		{
			break;
		}
		if(b % 2)
		{
			std::cout << "0" << std::endl;
			continue;
		}
		b = b / 2 - a;
		if(b < 0 || a < b)
		{
			std::cout << "0" << std::endl;
			continue;
		}
			std::cout << b << " " << a - b << std::endl;
	}
	return 0;
}

