#include <iostream>

int main(int argc, char **argv)
{
	int map[19][19], N, x, y;
	for(int i = 0; i < 19; i++)
	{
		for(int j = 0; j < 19; j++)
		{
			std::cin >> map[i][j];
		}
	}
	std::cin >> N;
	for(int i = 0; i < N; i++)
	{
		std::cin >> x;
		std::cin >> y;
		x -= 1;
		y -= 1;
		for(int j = 0; j < 19; j++)
		{
			map[y][j] = 1 - map[y][j];
			map[j][x] = 1 - map[j][x];
		}
	}
	for(int i = 0; i < 19; i++)
	{
		for(int j = 0; j < 19; j++)
		{
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

