#include <stdio.h>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T, N, P;
	int a[110];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &P);
		for(int i = 0; i < P; i++)
			scanf("%d", &a[i]);
		int cnt = 0;
		for(int day = 1; day <= N; day++)
			if((day-1) % 7 < 5)
			{
				for(int i = 0; i < P; i++)
					if(day % a[i] == 0)
					{
						cnt++;
						break;
					}
			}
		printf("%d\n", cnt);

	}
	return 0;
}


