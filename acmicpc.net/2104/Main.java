import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int arr[] = new int[N];
		for(int i = 0; i < N; i++)
		{
			arr[i] = sc.nextInt();
		}
		System.out.println(new Main(arr).solve(0, arr.length));
	}

	int arr[];

	public Main(int arr[])
	{
		this.arr = arr;
	}

	public int solve(int offset, int len)
	{
		return 0;
	}
}
