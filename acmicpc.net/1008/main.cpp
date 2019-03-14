#include <iostream>
#include <iomanip>

int main(int argc, char **argv)
{
	int A, B;
	std::cin >> A;
	std::cin >> B;
	std::cout << std::setprecision(10) << (double) A / B << std::endl;
	return 0;
}

