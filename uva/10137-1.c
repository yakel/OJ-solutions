#include <stdio.h>
#define PRECISION 10e-6

int main()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int n,i;
	double aver,sum,sum1,sum2,aver_floor,aver_ceil;
	double cost[1010];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&cost[i]);
			sum+=cost[i];
		}
		aver=sum/n;
		aver_floor=aver_ceil=((int)(aver*100))/100.0;
		if(aver_ceil<aver)
			aver_ceil=((int)(aver_ceil*100+1.1))/100.0;
		sum1=sum2=0;
		for(i=0;i<n;i++)
		{
			if(cost[i]<aver)
				sum1+=aver_floor-cost[i];
			else sum2+=cost[i]-aver_ceil;
		}
		if(sum1>sum2) printf("$%.2lf\n",sum1);
		else printf("$%.2lf\n",sum2);
	}
	return 0;
}
