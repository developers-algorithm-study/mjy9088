#include <iostream>

long solve(int s, int b)
{
	long result = 1;
	int tmp, p2 = 0, p3 = 0, p5 = 0, p7 = 0;
	for(int i = 0; i < s; i++)
	{
		tmp = b - i;
		while(tmp % 2 == 0) { p2++; tmp /= 2; }
		while(tmp % 3 == 0) { p3++; tmp /= 3; }
		while(tmp % 5 == 0) { p5++; tmp /= 5; }
		while(tmp % 7 == 0) { p7++; tmp /= 7; }
		result *= tmp;
	}
	for(int i = 0; i < s; i++)
	{
		tmp = i + 1;
		while(p2 && tmp % 2 == 0) { p2--; tmp /= 2; }
		while(p3 && tmp % 3 == 0) { p3--; tmp /= 3; }
		while(p5 && tmp % 5 == 0) { p5--; tmp /= 5; }
		while(p7 && tmp % 7 == 0) { p7--; tmp /= 7; }
		result /= tmp;
	}
	while(p2) { p2--; result *= 2; }
	while(p3) { p3--; result *= 3; }
	while(p5) { p5--; result *= 5; }
	while(p7) { p7--; result *= 7; }
	return result;
}

int main(int argc, char **argv)
{
	int T, N, M;
	std::cin >> T;
	for(int i = 0; i < T; i++)
	{
		std::cin >> N;
		std::cin >> M;
		std::cout << solve(N, M) << std::endl;
	}
	return 0;
}

