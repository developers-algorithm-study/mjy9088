#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main(int argc, char **argv)
{
	int N, tmp, i, j;
	std::cin >> N;
	long A[21], B[21], result = 0, *a = A, *b = B;
	if(!N)
	{
		std::cout << "0" << std::endl;
		return 0;
	}
	for(i = 0; i < 21; i++)
	{
		a[i] = 0;
	}
	std::cin >> tmp;
	a[tmp] = 1;
	for(i = 2; i < N; i++)
	{
		swap<long *>(a, b);
		for(j = 0; j < 21; j++)
		{
			a[j] = 0;
		}
		std::cin >> tmp;
		for(j = 0; j + tmp < 21; j++)
		{
			a[j] += b[j + tmp];
			a[j + tmp] += b[j];
		}
	}
	std::cin >> tmp;
	std::cout << a[tmp] << std::endl;
	return 0;
}

