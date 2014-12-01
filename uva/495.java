import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		BigInteger[] F = new BigInteger[5010];
		F[0] = BigInteger.valueOf(0);
		F[1] = BigInteger.valueOf(1);
		for (int i = 2; i <= 5000; i++)
			F[i] = F[i-1].add(F[i-2]);
		int n;
		while (sc.hasNext())
		{
			n = sc.nextInt();
			System.out.println("The Fibonacci number for " + n +" is " + F[n]);
		}
	}
}
