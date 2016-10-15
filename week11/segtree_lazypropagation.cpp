// array A[]

int tree[4 * MAXN];
int lazy[4 * MAXN];

void build(int l, int r, int idx) {
    if (l == r) {
        tree[idx] = A[l];
        return;
    }
    int left = idx << 1, right = left | 1, mid = (l + r) >> 1;
    build(l, mid, left);
    build(mid + 1, r, right);
    tree[idx] = tree[left] + tree[right];
}

void lazyUpdate(int l, int r, int idx) {
    if (lazy[idx]) {
        tree[idx] += (r - l + 1) * lazy[idx];
        if (l < r) {
            int left = idx << 1, right = left | 1;
            lazy[left] += lazy[idx];
            lazy[right] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void update(int l, int r, int idx, int i, int j, int v) {
    lazyUpdate(l, r, idx);
    if (r < i || j < l) return;
    if (i <= l && r <= j) {
        lazy[idx] += v;
        lazyUpdate(l, r, idx);
        return;
    }
    int left = idx << 1, right = left | 1, mid = (l + r) >> 1;
    update(l, mid, left, i, j, v);
    update(mid + 1, r, right, i, j, v);
    tree[idx] = tree[left] + tree[right];
}

int query(int l, int r, int idx, int i, int j) {
    lazyUpdate(l, r, idx);
    if (i <= l && r <= j) return tree[idx];
    if (r < i || j < l) return 0;
    int left = idx << 1, right = left | 1, mid = (l + r) >> 1;
    return query(l, mid, left, i, j) + query(mid + 1, r, right, i, j);
}

build(1, n, 1);         // 1-based
build(0, n - 1, 1);     // 0-based
