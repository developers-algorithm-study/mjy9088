import java.util.Scanner;

public class Main
{
	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int arr[] = new int[N];
		for(int i = 0; i < N; i++)
		{
			arr[i] = sc.nextInt();
		}
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				System.out.print(arr[(i + j) % N] + " ");
			}
			System.out.println();
		}
	}
}
