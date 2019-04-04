#include <iostream>

int main(int argc, char **argv)
{
	int N, M;
	std::cin >> N;
	std::cin >> M;
	if(N % 2 == 0 || N > 100 || N < 0 || M > 4 || 1 > M)
	{
		printf("INPUT ERROR!\n");
		return 0;
	}
	switch(M)
	{
		case 1:
			for(int i = 0; i < N; i++)
			{
				int j = N - i;
				int k = i + 1;
				for(j = j < k ? j : k; j; j--)
				{
					std::cout << "*";
				}
				std::cout << std::endl;
			}
			break;
		case 2:
			for(int i = 0; i < N; i++)
			{
				int k = N / 2 - i;
				k = k < 0 ? -k : k;
				for(int j = 0; j < k; j++)
				{
					std::cout << " ";
				}
				k = N / 2 - k + 1;
				for(int j = 0; j < k; j++)
				{
					std::cout << "*";
				}
				std::cout << std::endl;
			}
			break;
		case 3:
			for(int i = 0; i < N; i++)
			{
				int j = N - i - 1;
				int k = j < i ? j : i;
				for(j = 0; j < k; j++)
				{
					std::cout << " ";
				}
				k = N - k * 2;
				for(j = 0; j < k; j++)
				{
					std::cout << "*";
				}
				std::cout << std::endl;
			}
			break;
		default:
			for(int i = 0; i < N; i++)
			{
				int j = N - i - 1;
				int k = j < i ? j : i;
				for(j = 0; j < i && j < N / 2; j++)
				{
					std::cout << " ";
				}
				k = N / 2 - k + 1;
				for(j = 0; j < k; j++)
				{
					std::cout << "*";
				}
				std::cout << std::endl;
			}
	}
	return 0;
}

