import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger[] fact = new BigInteger[370];
		fact[0] = BigInteger.valueOf(1);
		for (int i = 1; i <= 366; i++)
			fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
		int[] cnt = new int[10];
		int n;
		while (sc.hasNext())
		{
			n = sc.nextInt();
			if (n == 0)  break;
			BigInteger f = fact[n];
			for (int i = 0; i < 10; i++)  cnt[i] = 0;
			while (f.compareTo(BigInteger.ZERO) > 0)
			{
				BigInteger r = f.mod(BigInteger.valueOf(10));
				int idx = r.intValue();
				cnt[idx]++;
				f = f.divide(BigInteger.valueOf(10));
			}
			System.out.printf("%d! --\n", n);
			System.out.printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]);
			System.out.printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n", cnt[5], cnt[6], cnt[7], cnt[8], cnt[9]);
		}
	}
}
