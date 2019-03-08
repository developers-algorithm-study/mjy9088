#include <iostream>

int abs(int a)
{
	return a < 0 ? -a : a;
}

int main(int argc, char **argv)
{
	int N, X, Y;
	std::cin >> N;
	std::cin >> Y;
	std::cin >> X;
	X -= 1;
	Y -= 1;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			std::cout << abs(X - j) + abs(Y - i) + 1 << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

