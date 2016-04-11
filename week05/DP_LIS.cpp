/*

Dynamic Programming
Longest Increasing Subsequence

O(N^2)

*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int a[MAXN];
int lis[MAXN];
// lis[i] -> length of LIS ending at i

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}

	int longest = 1;
	lis[0] = 1;

	for (int i = 1; i < n; ++i)
	{
		lis[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (a[i] > a[j])	// if the number is (strictly) increasing
			{
				lis[i] = max(lis[i], lis[j] + 1);
			}
		}
		longest = max(longest, lis[i]);
	}

	printf("%d\n", longest);

	return 0;
}
