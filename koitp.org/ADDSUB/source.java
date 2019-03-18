import java.util.Scanner;

public class source
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), tmp, i, j;
		long a[] = new long[21], b[] = new long[21], temp[];
		if(N == 0)
		{
			System.out.println("0");
			return;
		}
		for(i = 0; i < 21; i++)
		{
			a[i] = 0;
		}
		tmp = sc.nextInt();
		a[tmp] = 1;
		for(i = 2; i < N; i++)
		{
			temp = a;
			a = b;
			b = temp;
			for(j = 0; j < 21; j++)
			{
				a[j] = 0;
			}
			tmp = sc.nextInt();
			for(j = 0; j + tmp < 21; j++)
			{
				a[j] += b[j + tmp];
				a[j + tmp] += b[j];
			}
		}
		tmp = sc.nextInt();
		System.out.println(a[tmp]);
	}
}
