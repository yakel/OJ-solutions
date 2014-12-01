// the version is for joj 1904 
#include <cstdio>
#include <cstring>
#define REGN 10
#define RAMN 1000

int reg[REGN], ram[RAMN];

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif
	bool input_end = false;
	while (!input_end)
	{
		memset(ram, 0, sizeof(ram));
		int k = 0;
		while (1)
		{
			if (scanf("%d", &ram[k]) == EOF)
			{
				input_end = true;
				break;
			}
			if (ram[k] == -1)   break;
			k++;
		}
		int p = 0; 		// p point to the location that will execute
		int cnt = 0;
		memset(reg, 0, sizeof(reg));
		bool run_end = false;
		while (!run_end)
		{
			int hund = ram[p] / 100;
			int ten = (ram[p] % 100) / 10;
			int unit = ram[p] % 10;
			cnt++;
			switch(hund)
			{
				case 1:
					if (ram[p] == 100) 
					{
						run_end = true;
						break;
					}
				case 2:
					reg[ten] = unit;
					p++;
					break;
				case 3:
					reg[ten] += unit;
					reg[ten] %= 1000;
					p++;
					break;
				case 4:
					reg[ten] *= unit;
					reg[ten] %= 1000;
					p++;
					break;
				case 5:
					reg[ten] = reg[unit];
					p++;
					break;
				case 6:
					reg[ten] += reg[unit];
					reg[ten] %= 1000;
					p++;
					break;
				case 7:
					reg[ten] *= reg[unit];
					reg[ten] %= 1000;
					p++;
					break;
				case 8: 
					reg[ten] = ram[reg[unit]];
					p++;
					break;
				case 9:
					ram[reg[unit]] = reg[ten];
					p++;
					break;
				case 0:
					if (reg[unit] != 0)   p = reg[ten];
					else p++;
					break;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
