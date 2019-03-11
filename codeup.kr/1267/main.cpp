#include <iostream>

int main(int argc, char **argv)
{
	int N, tmp, result = 0;
	std::cin >> N;
	while(int i = 0; i < N; i++)
	{
		std::cin >> tmp;
		if(tmp % 5 == 0)
		{
			result += tmp;
		}
	}
	std::cout << result << std::endl;
	return 0;
}

