import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int kase = 0;
		while (true)
		{
			int n = sc.nextInt();
			int f = sc.nextInt();
			if (n == 0 && f == 0)  break;
			kase++;
			BigInteger sum = BigInteger.valueOf(0);
			for (int i = 0; i < n; i++)
			{
				BigInteger t = sc.nextBigInteger();
				sum = sum.add(t);
			}
			BigInteger aver = sum.divide(BigInteger.valueOf(f));
			System.out.println("Bill #" + kase + " costs " + sum + ": each friend should pay " + aver);
			System.out.println();
		}
	}
}
