import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int i = 0; i < T; i++)
		{
			System.out.println(solve(sc.nextInt(), sc.nextInt()).toString());
		}
	}

	public static BigInteger solve(int s, int b)
	{
		BigInteger result = BigInteger.ONE;
		for(int i = 0; i < s; i++)
		{
			result = result.multiply(new BigInteger(Integer.toString(b - i)));
		}
		for(int i = 0; i < s; i++)
		{
			result = result.divide(new BigInteger(Integer.toString(i + 1)));
		}
		return result;
	}
}
