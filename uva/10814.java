import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		while (T-- > 0)
		{
			BigInteger a = cin.nextBigInteger();
			String ch = cin.next();
			BigInteger b = cin.nextBigInteger();
			BigInteger c = a.gcd(b);
			System.out.println(a.divide(c) + " / " + b.divide(c));
		}
	}
}
