#include <iostream>

int main(int argc, char **argv)
{
	int N, i, j;
	std::cin >> N;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			std::cout << ((i + (i % 2)) * N + j * (1 - (i % 2) * 2) + (i + 1) % 2) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

