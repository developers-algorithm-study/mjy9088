import java.util.Scanner;

public class Main
{
	public static int abs(int a)
	{
		return a < 0 ? -a : a;
	}

	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), Y = sc.nextInt() - 1, X = sc.nextInt() - 1;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				System.out.print((abs(X - j) + abs(Y - i) + 1) + " ");
			}
			System.out.println();
		}
	}
}
