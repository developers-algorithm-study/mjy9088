import java.util.Scanner;

public class Main
{
	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt(), N = sc.nextInt(), sum = 0;
		for(int i = 0; i < T; i++)
		{
			sc.next();
			sum += sc.nextInt();
		}
		System.out.println(N * 3 - sum);
	}
}
