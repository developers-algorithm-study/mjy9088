#include <iostream>

int main(int argc, char **argv)
{
	int N, M;
	std::cin >> N;
	std::cin >> M;
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	return 0;
}

