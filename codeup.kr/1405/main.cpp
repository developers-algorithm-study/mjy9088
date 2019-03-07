#include <iostream>

int main(int argc, char **argv)
{
	int N, i, j;
	std::cin >> N;
	int arr[N];
	for(i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			std::cout << arr[(i + j) % N] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

