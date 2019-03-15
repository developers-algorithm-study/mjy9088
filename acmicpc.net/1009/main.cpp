#include <iostream>

int solve(int a, int b)
{
	if(b == 1)
	{
		return a % 10;
	}
	if(b % 2)
	{
		return a * solve((a * a) % 10, b / 2) % 10;
	}
	else
	{
		return b ? solve((a * a) % 10, b / 2) % 10 : 1;
	}
}

int main(int argc, char **argv)
{
	int T, A, B, i;
	std::cin >> T;
	for(i = 0; i < T; i++)
	{
		std::cin >> A;
		std::cin >> B;
		std::cout << (9 + solve(A, B)) % 10 + 1 << std::endl;
	}
	return 0;
}

