import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextInt())
		{
			int n = sc.nextInt();
			BigInteger a = BigInteger.valueOf(sc.nextInt());
			BigInteger sum = BigInteger.valueOf(0);
			BigInteger t = BigInteger.valueOf(1);
			for (int i = 1; i <= n; i++)
			{
				t = t.multiply(a);
				BigInteger tmp = t.multiply(BigInteger.valueOf(i));
				sum = sum.add(tmp);
			}
			System.out.println(sum);
		}
	}
}
