/*

Dynamic Programming
Longest Palindromic Subsequence
O(N^2)

*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int dp[MAXN][MAXN];
char s[MAXN];

int calc(int l, int r)
{
	if (r < l) return 0;	// overlap
	if (l == r) return 1;	// same position: length = 1
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	ret = max(calc(l + 1, r), calc(l, r - 1));
	if (s[l] == s[r])
	{
		ret = max(ret, 2 + calc(l + 1, r - 1));
	}
	return ret;
}

int main()
{
	scanf("%s", s);
	memset(dp, -1, sizeof dp);
	printf("%d\n", calc(0, strlen(s) - 1));
	return 0;
}
