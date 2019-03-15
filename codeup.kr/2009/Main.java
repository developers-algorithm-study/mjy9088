import java.util.Scanner;

public class Main
{
	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), M = sc.nextInt();
		System.out.println(N != 0 ? (N - 1) / (M - 1) : 0);
	}
}
