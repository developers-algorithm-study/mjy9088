import java.util.Scanner;

public class Main
{
	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), i, x = 0, y = -1, s, c = 1;
		int arr[][] = new int[N][N];
		for(s = N; s != 0; s -= 2)
		{
			arr[++y][x] = c++;
			if(s == 1) break;
			for(i = 1; i < s; i++)
			{
				arr[++y][x] = c++;
			}
			for(i = 1; i < s; i++)
			{
				arr[y][++x] = c++;
			}
			for(i = 1; i < s; i++)
			{
				arr[--y][x] = c++;
			}
			for(i = 2; i < s; i++)
			{
				arr[y][--x] = c++;
			}
		}
		for(i = 0; i < N; i++)
		{
			for(s = 0; s < N; s++)
			{
				System.out.print(arr[i][s] + " ");
			}
			System.out.println();
		}
	}
}
