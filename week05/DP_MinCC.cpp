/*

Dynamic Programming
Coin Change (Minimum)

*/

#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1005;
const int INF = 0x3f3f3f;
const int NUMC = 5;

int coin[] = {1, 3, 4, 10, 15};

int minCC[MAXV];

int main()
{
	minCC[0] = 0;	// to make 0, we don't need any coins

	for (int i = 1; i < MAXV; ++i)
	{
		minCC[i] = INF;		// set to +infinity to find minimum value
		for (int j = 0; j < NUMC; ++j)
		{
			// if the nominal we want to achieve is not smaller than j-th coin
			if (i >= coin[j])
			{
				// we use 1 coin of type j (coin[j])
				minCC[i] = min(minCC[i], minCC[i - coin[j]] + 1);
			}
		}
	}

	// the answers are stored in minCC[]
	// the minimum number of coins required to make N is minCC[N]

	return 0;
}
