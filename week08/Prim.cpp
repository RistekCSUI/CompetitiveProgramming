#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101010;

int num_nodes, num_edges, u, v, w, source;
vector<pair<int, int> > adj[MAXN];
int dist[MAXN];

int main()
{
	scanf("%d %d", &num_nodes, &num_edges);
	for (int i = 0; i < num_edges; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({v, w});
	}
	for (int i = 0; i < num_nodes; ++i)
		dist[i] = 0x3f3f3f3f;

	priority_queue<pair<int, int> > pq;
	pq.push({0, 0});
	dist[0] = 0;
	int ans = 0;
	while (!pq.empty())
	{
		pair<int, int> u = pq.top();
		pq.pop();
		u.first = -u.first;
		if (dist[u.second] == u.first)
		{
			ans += u.first;
			for (pair<int, int> v : adj[u.second])
			{
				if (dist[v.first] > v.second)
				{
					dist[v.first] = v.second;
					pq.push({-dist[v.first], v.first});
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}