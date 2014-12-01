import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger[] fact = new BigInteger[110];
		fact[0] = BigInteger.ONE;
		for (int i = 1; i <= 100; i++)
			fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
		int n, m;
		while (sc.hasNext())
		{
			n = sc.nextInt();
			m = sc.nextInt();
			if (n == 0 && m == 0)  break;
			BigInteger ans = fact[n].divide(fact[m]).divide(fact[n-m]);
			System.out.println(n + " things taken " + m + " at a time is " + ans + " exactly.");
		}

	}
}
