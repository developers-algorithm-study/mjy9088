import java.util.Scanner;

public class Main
{
	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				System.out.print((i + (i % 2)) * N + j * (1 - (i % 2) * 2) + (i + 1) % 2 + " ");
			}
			System.out.println();
		}
	}
}
