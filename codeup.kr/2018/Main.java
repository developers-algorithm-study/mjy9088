import java.util.Scanner;

public class Main
{
	public static void main(String... args)
	{
		Scanner sc = new Scanner(System.in);
		int S = sc.nextInt(), E = sc.nextInt();
		if(S == 1)
		{
			System.out.println("1 ");
		}
		S -= 2;
		if(E == 1)
		{
			return;
		}
		int an[] = new int[452], ac[] = new int[452], bn[] = new int[591], bc[] = new int[591], len;
		len = an[0] = ac[0] = 1;
		for(int i = 1; i < E; i++)
		{
			int tmp[] = an;
			an = bn;
			bn = tmp;
			tmp = ac;
			ac = bc;
			bc = tmp;
			an[0] = bn[0];
			ac[0] = 1;
			int idx = 0;
			if(an[0] == bc[0])
			{
				ac[0]++;
			}
			else
			{
				an[1] = bc[0];
				ac[++idx] = 1;
			}
			if(S < i)
			{
				System.out.print(bn[0] + " " + bc[0] + " ");
			}
			for(int j = 1; j < len; j++)
			{
				if(S < i)
				{
					System.out.print(bn[j] + " " + bc[j] + " ");
				}
				if(an[idx] == bn[j])
				{
					ac[idx]++;
				}
				else
				{
					an[++idx] = bn[j];
					ac[idx] = 1;
				}
				if(an[idx] == bc[j])
				{
					ac[idx]++;
				}
				else
				{
					an[++idx] = bc[j];
					ac[idx] = 1;
				}
			}
			if(S < i)
			{
				System.out.println();
			}
			len = idx + 1;
		}
	}
}
