/*

Dynamic Programming
0/1 Knapsack Problem
Top-down Approach

*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
const int MAXW = 1005;

int N, W;
int w[MAXN], v[MAXN];
int dp[MAXN][MAXW];

int calc(int i, int left)
{
	if (i == N) return 0;	// we have tried all items
	int &ret = dp[i][left];
	if (ret != -1) return ret;
	// we can omit the i-th item
	ret = calc(i + 1, left);
	// or if we use the i-th item
	// we get +v[i]
	// the remaining sack -w[i]
	ret = max(ret, v[i] + calc(i + 1, left - w[i]));
	return ret;
}

int main()
{
	// N is the number of items
	// W is the capacity of the sack
	scanf("%d %d", &N, &W);
	for (int i = 0; i < N; ++i)
		scanf("%d %d", &w[i], &v[i]);
	// assume that -1 means not used (or not visited)
	memset(dp, -1, sizeof dp);
	
	printf("%d\n", calc(0, W));
	return 0;
}
