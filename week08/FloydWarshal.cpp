#include <bits/stdc++.h>

using namespace std;

const int MAXN = 222;

int num_nodes, num_edges, u, v, w;
int dist[MAXN][MAXN];

void init()
{
	for (int i = 0; i < num_nodes; ++i)
		for (int j = 0; j < num_nodes; ++j)
			dist[i][j] = (i != j) * 0x3f3f3f3f;
}

int main()
{
	scanf("%d %d", &num_nodes, &num_edges);
	init();
	for (int i = 0; i < num_edges; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		dist[u][v] = min(dist[u][v], w);
	}

	for (int k = 0; k < num_nodes; ++k)
		for (int i = 0; i < num_nodes; ++i)
			for (int j = 0; j < num_nodes; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 0; i < num_nodes; ++i)
		for (int j = 0; j < num_nodes; ++j)
			if (dist[i][j] != 0x3f3f3f3f && i != j)
				printf("from %d to %d = %d\n", i, j, dist[i][j]);
	return 0;
}