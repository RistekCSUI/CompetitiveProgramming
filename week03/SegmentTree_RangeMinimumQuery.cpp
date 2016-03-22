#include <algorithm>
#include <stdio.h>

using namespace std;

const int MAXN = 100000;
const int MAX_INT = 2147483647;

int tree[4 * MAXN];
int arr[MAXN];

void build(int b, int e, int i)
{
	if (b < e)
	{
		build(b, (b + e) / 2, i * 2);
		build((b + e) / 2 + 1, e, i * 2 + 1);
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}
	else
		tree[i] = arr[b];
}

void update(int b, int e, int i, int p, int v)
{
	if (b == p && p == e)
	{
		tree[i] = v;
		return;
	}
	if (p < b || p > e) return;
	update(b, (b + e) / 2, i * 2, p, v);
	update((b + e) / 2 + 1, e, i * 2 + 1, p, v);
	tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

int query(int b, int e, int i, int l, int r)
{
	if (l <= b && e <= r) return tree[i];
	if (r < b || l > e) return -MAX_INT;
	return min(
		query(b, (b + e) / 2, i * 2, l, r), 
		query((b + e) / 2 + 1, e, i * 2 + 1, l, r)
		);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	build(0, n - 1, 1);
	int q, type, a, b;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d %d %d", &type, &a, &b);
		if (type == 0)
		{
			printf("%d\n", query(0, n - 1, 1, a, b));
		}
		else
		{
			update(0, n - 1, 1, a, b);
		}
	}
	return 0;
}