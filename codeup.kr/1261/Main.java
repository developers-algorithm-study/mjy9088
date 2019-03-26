import java.util.Scanner;

public class Main
{
	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
		for(int i = 0; i < 10; i++)
		{
			int tmp = sc.nextInt();
			if(tmp % 5 == 0)
			{
				System.out.println(tmp);
				return;
			}
		}
		System.out.println("0");
	}
}
