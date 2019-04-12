double myPow(double x, int n)
{
	double result = 1.0;
	double tmp = x;
	long int temp = 1;
	long int test = n;
	if(n < 0)
	{
		test = -test;
		tmp = 1 / tmp;
	}
	while(test)
	{
		if(temp & test)
		{
			result *= tmp;
			test ^= temp;
		}
		tmp = tmp * tmp;
		temp *= 2;
	}
	return result;
}

