#include <iostream>
#define NUM 100

using namespace std;

/*
12 16
1 2 32
1 4 35
1 11 125
2 3 130
2 12 25
3 12 120
4 5 26
4 6 36
5 6 25
6 7 36
7 8 22
7 9 56
8 9 42
8 10 53 
10 11 81
11 12 38
*/

int n;
int m;
int a[NUM][NUM];
int x[NUM];
int bestx[NUM];
int cc;
int bestc;
int NoEdge = -1;
 
void Backtrack(int t)
{
	if(t==n)
	{
		if(a[x[n-1]][x[n]]!= NoEdge && a[x[n]][1]!= NoEdge && 
			(cc + a[x[n-1]][x[n]]+a[x[n]][1]<bestc||bestc== NoEdge))
		{
			for(int i=1; i<=n; i++)
				bestx[i] = x[i];
			bestc = cc + a[x[n-1]][x[n]] + a[x[n]][1];
		}
		return;
	}
	else 
	{
		for(int i=t; i<=n; i++)
		{
			if(a[x[t-1]][x[i]]!= NoEdge &&
				(cc + a[x[t-1]][x[i]]< bestc||bestc == NoEdge)) 
			{
				swap(x[t],x[i]);
				cc += a[x[t-1]][x[t]];
				Backtrack(t+1);
				cc -= a[x[t-1]][x[t]];
				swap(x[t],x[i]);
			}
		}
	}
}
 
int main() 
{
	int i, j;
	int from, to, length;

	scanf("%d%d", &n, &m); 

	for (i = 0; i < NUM; i++)
		for (j=1; j < NUM; j++)
			a[i][j] = NoEdge;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &from, &to, &length);
		a[from][to] = length;
		a[to][from] = length;
	}
	bestc = NoEdge;
	for(i = 1; i<=n; i++)
		x[i] = i;
	Backtrack(2);
	for(j=1; j<=n; j++)
		printf("%d ", bestx[j]);
	printf("\n%d\n", bestc);
    return 0;
}