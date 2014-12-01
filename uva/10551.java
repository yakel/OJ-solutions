import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		while (true)
		{
			int base = sc.nextInt();
			if (base == 0)  break;
			String p_str = sc.next();
			BigInteger p = new BigInteger(p_str, base);
			String m_str = sc.next();
			BigInteger m = new BigInteger(m_str, base);
			System.out.println((p.mod(m)).toString(base));
		}
	}
}
