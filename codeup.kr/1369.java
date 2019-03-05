import java.util.Scanner;

class Main
{
	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), K = sc.nextInt();
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(i == 0 || j == 0 || i == N - 1 || j == N - 1 || (i + j) % K == K - 1)
				{
					System.out.print('*');
				}
				else
				{
					System.out.print(' ');
				}
			}
			System.out.println();
		}
	}
}
