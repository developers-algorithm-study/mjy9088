#include <iostream>

int main(int argc, char **argv)
{
	int N, M;
	std::cin >> N;
	std::cin >> M;
	std::cout << (N ? (N - 1) / (M - 1) : 0) << std::endl;
	return 0;
}

