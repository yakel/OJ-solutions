// It's wrong!
#include <cstdio>
#include <cstring>

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	char str[110];
	int left[26][110], right[26][110];
	while (T--)
	{
		scanf("%s", str);
		int cnt[30] = {0};
		for (int i = 0; str[i] != '\0'; i++)
			cnt[str[i]-'a']++;
		int t = 0;
		for (int i = 0; i < 26; i++)
			if (cnt[i] % 2)  t++;
		if (t > 1)
		{
			printf("Impossible\n");
			continue;
		}
		memset(left, -1, sizeof(left));
		for (int i  = 0; str[i] != '\0'; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (str[i]-'a' == j)  left[j][i] = i;
				else  if (i > 0)  left[j][i] = left[j][i-1];
			}
		}
		int len = strlen(str);
		memset(right, -1, sizeof(right));
		for (int i = len-1; i >= 0; i--)
		{
			for (int j = 0; j < 26; j++)
			{
				if (str[i]-'a' == j)  right[j][i] = i;
				else if (i < len-1)  right[j][i] = right[j][i+1];
			}
		}
		for (int i = 0; i < 26; i++)
			if (cnt[i])
		{
		
			for (int j = 0; j < strlen(str); j++)
				;//printf("%c %d: %d %d\n", 'a'+i, j, left[i][j], right[i][j]);
		}
		int ans = 0;
		for (int s = 0, e = strlen(str)-1; s < e; s++, e--)
		{
			if (str[s] != str[e])
			{
				int lmin = 1000, p = -1, q = -1;
				for (int i = 0; i < 26; i++)
					if (right[i][s] != -1 && left[i][e] != -1)
				{
					int t = right[i][s] - s + e - left[i][e];
					if (t < lmin)
					{
						lmin = t;
						p = right[i][s];
						q = left[i][e];
					}
				}
				printf("%d %d %d\n", lmin, p, q);
				ans += lmin;
				for (int i = p; i > s; i--)  
					str[i] = str[i-1];
				for (int i = q; i < e; i++)
					str[i] = str[i+1];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
