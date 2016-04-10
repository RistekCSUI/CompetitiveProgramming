/*

Dynamic Programming
0/1 Knapsack Problem
Bottom-up Approach

*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
const int MAXW = 1005;

int N, W;
int dp[MAXN][MAXW];

int w[MAXN], v[MAXN];

int dp[MAXN][MAXW];

int main()
{
	scanf("%d %d", &N, &W);	

	for (int i = 1; i <= N; ++i)
	{
		scanf("%d %d", &w[i], &v[i]);
	}	

	// assume dp[][] has already set to zeroes
	// dp[0][i] = 0 -> have not checked any items
	// dp[i][0] = 0 -> by using capacity 0, we cannot have any items	

	for (int i = 1; i <= N; ++i)	// for each item
	{
		for (int j = 1; j <= W; ++j)
		{
			if (j >= w[i])	// if we can take this item
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	// the answer is at dp[N][W];
	
	printf("%d\n", dp[N][W]);

	return 0;
}
