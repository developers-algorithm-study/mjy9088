#include <iostream>

int main(int argc, char **argv)
{
	int N;
	char *stars = (char *)"********************************************"
		"********************************************************" + 99;
	std::cin >> N;
	for(int i = 0; i < N; i++)
	{
		std::cout << stars - i << std::endl;
	}
	return 0;
}

