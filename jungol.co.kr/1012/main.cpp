#include <iostream>

int main(int argc, char **argv)
{
	int T, N, sum = 0;
	char garbage[11];
	std::cin >> T;
	std::cin >> N;
	for(int i = 0; i < T; i++)
	{
		int tmp;
		std::cin >> garbage;
		std::cin >> tmp;
		sum += tmp;
	}
	std::cout << N * 3 - sum << std::endl;
	return 0;
}

