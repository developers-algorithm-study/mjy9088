#include <iostream>

int main(int argc, char **argv)
{
	int W, H, result = 64;
	std::cin >> H;
	std::cin >> W;
	int tmp[H][W + 7];
	char temp;
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W + 7; j++)
		{
			tmp[i][j] = 0;
		}
		for(int j = 0; j < W; j++)
		{
			std::cin >> temp;
			for(int k = 0; k < 8; k++)
			{
				if((i + k) % 2 == (temp == 'W' ? 0 : 1))
				{
					tmp[i][j + k]++;
				}
			}
		}
	}
	for(int i = 0; i < H - 7; i++)
	{
		for(int j = 7; j < W; j++)
		{
			int w = 0, b = 0;
			for(int k = 0; k < 8; k++)
			{
				w += 8 - tmp[i + k][j];
				b += tmp[i + k][j];
			}
			if(result > w)
			{
				result = w;
			}
			if(result > b)
			{
				result = b;
			}
		}
	}
	std::cout << result << std::endl;
	return 0;
}

