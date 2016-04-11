/*

Dynamic Programming
Longest Common Subsequence
O(N^2)

*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

char a[MAXN], b[MAXN];

int dp[MAXN][MAXN];
// dp[i][j] -> length of LCS of a[1..i] and b[1..j]

int main()
{
	scanf("%s%s", a + 1, b + 1);	// get string a and b (1-based)

	int n = strlen(a + 1), m = strlen(b + 1);
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			if (a[i] == b[j])	// common character
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}

	printf("%d\n", dp[n][m]);
	
	return 0;
}
