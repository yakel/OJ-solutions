/*
ID: yake.ab1
PROB: ride
LANG: C++
*/
#include <cstdio>
#include <cstring>

int main()
{
	FILE *fin = fopen("ride.in", "r");
	FILE *fout = fopen("ride.out", "w");
	char comet[10], group[10];
	fscanf(fin, "%s", comet);
	fscanf(fin, "%s", group);
	int a = 1;
	for(int i = 0; i < strlen(comet); i++)
		a *= (comet[i] - 'A' + 1);
	int b = 1;
	for(int i = 0; i < strlen(group); i++)
		b *= (group[i] - 'A' + 1);
	if(a % 47 == b % 47)   fprintf(fout, "GO\n");
	else fprintf(fout, "STAY\n");
	return 0;
}
