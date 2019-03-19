#include <iostream>

struct i2
{
	int n, c;
};

template<typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

int main(int argc, char **argv)
{
	int S, E, i, j, len, idx;
	std::cin >> S;
	std::cin >> E;
	if(S == 1)
	{
		std::cout << "1 " << std::endl;
	}
	S -= 2;
	if(E == 1)
	{
		return 0;
	}
	i2 A[452], B[591], *a = A, *b = B;
	len = 1;
	a[0] = (i2){1, 1};
	for(i = 1; i < E; i++)
	{
		swap<i2 *>(a, b);
		a[idx = 0] = (i2){b[0].n, 1};
		if(a[idx].n == b[0].c)
		{
			a[idx].c++;
		}
		else
		{
			a[++idx] = (i2){b[0].c, 1};
		}
		if(S < i)
		{
			std::cout << b[0].n << " " << b[0].c << " ";
		}
		for(j = 1; j < len; j++)
		{
			if(S < i)
			{
				std::cout << b[j].n << " " << b[j].c << " ";
			}
			if(a[idx].n == b[j].n)
			{
				a[idx].c++;
			}
			else
			{
				a[++idx] = (i2){b[j].n, 1};
			}
			if(a[idx].n == b[j].c)
			{
				a[idx].c++;
			}
			else
			{
				a[++idx] = (i2){b[j].c, 1};
			}
		}
		if(S < i)
		{
			std::cout << std::endl;
		}
		len = idx + 1;
	}
	return 0;
}

