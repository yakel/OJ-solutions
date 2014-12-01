import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while (T-- > 0)
		{
			BigInteger x = BigInteger.valueOf(sc.nextInt());
			BigInteger y = BigInteger.valueOf(sc.nextInt());
			BigInteger n = BigInteger.valueOf(sc.nextInt());
			System.out.println(x.modPow(y, n));
		}
	}
}
