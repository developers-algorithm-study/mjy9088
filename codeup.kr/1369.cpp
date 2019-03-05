#include <iostream>

char *star = (char *)((size_t) "                                       "
	"                                                           *" + 98);

int nextInt()
{
	bool negative = false;
	register int ret = 0, c;
	c = getchar();
    if(c == '-')
	{
		negative = true;
		c = getchar();
	}
	for(; (c > 47 && c < 58); c = getchar())
		ret = ret * 10 + c - '0';
	if (negative)
		ret *= -1;
	return ret;
}

int printStar(int spacesBeforeStar)
{
	std::cout << star - spacesBeforeStar;
}

int main(int argc, char **argv)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N = nextInt(), K = nextInt();
	if(N == 1)
	{
		std::cout << "*";
		return 0;
	}
	N -= 2;
	for(int i = 0; i < N; i++)
	{
		std::cout << "*";
	}
	std::cout << "**\n*";
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= N; j++)
		{
			int tmp = K - (i + j + 2) % K - 1;
			j += tmp;
			if(j > N) tmp -= j - N;
			printStar(tmp);
		}
		std::cout << "\n*";
	}
	for(int i = 0; i < N; i++)
	{
		std::cout << "*";
	}
	std::cout << "*";
	return 0;
}
