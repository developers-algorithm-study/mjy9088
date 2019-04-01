import java.util.Scanner;

public class Solution
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), M = sc.nextInt();
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < N; j++)
			{
				System.out.print("*");
			}
			System.out.println();
		}
	}
}
