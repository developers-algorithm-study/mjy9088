import java.util.Scanner;

public class Main
{
	static int solve(int a, int b)
	{
		if(b == 1)
		{
			return a % 10;
		}
		if(b % 2 == 1)
		{
			return a * solve((a * a) % 10, b / 2) % 10;
		}
		else
		{
			return b != 0 ? solve((a * a) % 10, b / 2) % 10 : 1;
		}
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int i = 0; i < T; i++)
		{
			System.out.println((9 + solve(sc.nextInt(), sc.nextInt())) % 10 + 1);
		}
	}
}
