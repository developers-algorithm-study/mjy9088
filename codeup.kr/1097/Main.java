import java.util.Scanner;

public class Main
{
	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
		int map[][] = new int[19][19];
		for(int i = 0; i < 19; i++)
		{
			for(int j = 0; j < 19; j++)
			{
				map[i][j] = sc.nextInt();
			}
		}
		int N = sc.nextInt();
		for(int i = 0; i < N; i++)
		{
			int x = sc.nextInt() - 1, y = sc.nextInt() - 1;
			for(int j = 0; j < 19; j++)
			{
				map[y][j] = 1 - map[y][j];
				map[j][x] = 1 - map[j][x];
			}
		}
		for(int i = 0; i < 19; i++)
		{
			for(int j = 0; j < 19; j++)
			{
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
	}
}
