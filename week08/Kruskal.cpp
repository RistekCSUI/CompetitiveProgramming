#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101010;
const int MAXE = 505050;

pair<int, pair<int, int> > edge[MAXE];
int p[MAXN];
int numSets;
int num_edges, num_nodes;
int u, v, w;

void init()
{
	for (int i = 0; i < num_nodes; ++i)
		p[i] = i;
	numSets = num_nodes;
}

int find(int u)
{
	return p[u] == u ? u : p[u] = find(p[u]);
}

int main()
{
	scanf("%d %d", &num_nodes, &num_edges);
	for (int i = 0; i < num_edges; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		edge[i] = {w, {u, v}};
	}
	sort(edge, edge + num_edges);
	init();
	int ans = 0;
	for (int i = 0; numSets > 1 && i < num_edges; ++i)
	{
		int x = find(edge[i].second.first), y = find(edge[i].second.second);
		if (x != y)
		{
			p[x] = y;
			ans += edge[i].first;
			--numSets;
		}
	}
	printf("%d\n", ans);
	return 0;
}