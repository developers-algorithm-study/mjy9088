#include <iostream>

int main(int argc, char **argv)
{
	int N, i, x = 0, y = -1, s, c = 1;
	std::cin >> N;
	int arr[N][N];
	for(s = N; s; s -= 2)
	{
		arr[++y][x] = c++;
		if(s == 1) break;
		for(i = 1; i < s; i++)
		{
			arr[++y][x] = c++;
		}
		for(i = 1; i < s; i++)
		{
			arr[y][++x] = c++;
		}
		for(i = 1; i < s; i++)
		{
			arr[--y][x] = c++;
		}
		for(i = 2; i < s; i++)
		{
			arr[y][--x] = c++;
		}
	}
	for(i = 0; i < N; i++)
	{
		for(s = 0; s < N; s++)
		{
			std::cout << arr[i][s] << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}

