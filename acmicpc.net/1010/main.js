var sc = new java.util.Scanner(java.lang.System["in"]);

function solve(s, b)
{
	var result = java.math.BigInteger.ONE;
	for(var i = 0; i < s; i++)
	{
		result = result.multiply(new java.math.BigInteger(b - i));
	}
	for(var i = 0; i < s; i++)
	{
		result = result.divide(new java.math.BigInteger(i + 1));
	}
	return result;
}

var T = sc.nextInt();
for(var i = 0; i < T; i++)
{
	java.lang.System.out.println(solve(sc.nextInt(), sc.nextInt()).toString());
}
