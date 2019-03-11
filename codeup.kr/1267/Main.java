import java.util.Scanner;

public class Main
{
	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), result = 0;
		for(int i = 0; i < N; i++)
		{
			int tmp = sc.nextInt();
			if(tmp % 5 == 0)
			{
				result += tmp;
			}
		}
		System.out.println(result);
	}
}
