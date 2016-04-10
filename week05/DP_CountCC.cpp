/*

Dynamic Programming
Coin Change (Counting Ways)

*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
const int NUMC = 5;
const int MOD = 1000000007;

int coin[] = {1, 2, 5, 10, 20};
int wayCC[MAXN];

int main()
{
	wayCC[0] = 1;	// to make 0, we have 1 way: by not using any coins
	
	for (int i = 1; i < MAXN; ++i)
	{
		wayCC[i] = 0;
		for (int j = 0; j < NUMC; ++j)
		{
			// if the nominal we want to achieve is not smaller than j-th coin
			if (i >= coin[j])
			{
				(wayCC[i] += wayCC[i - coin[j]]) %= MOD;
			}
		}
	}	

	// the answers are stored in wayCC[]
	// the number of ways to make N (modulo MOD) is wayCC[N]

	return 0;
}
