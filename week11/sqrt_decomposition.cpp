// const int MAXN = 60000;
// const int SQRTN = 250;
// const int INF = 2e9;

int initial[MAXN];
int arr[SQRTN][SQRTN];
int ans[SQRTN];
int n; // size of the input array

void preprocess() {
    for (int i = 0; i < n; ++i) {
        arr[i / SQRTN][i % SQRTN] = initial[i];
    }
}

int query(int row, int l, int r) {
    int ret = INF;
    for (int i = l; i <= r; ++i) {
        ret = min(ret, arr[row][i]);
    }
    return ret;
}

int query(int l, int r) {
    int r1 = l / SQRTN, r2 = r / SQRTN;
    int c1 = l % SQRTN, c2 = r % SQRTN;
    if (r1 == r2) return query(r1, c1, c2);
    int ret = INF;
    for (int i = r1 + 1; i < r2; ++i) {
        ret = min(ret, ans[i]);
    }
    return min(ret, min(query(r1, c1, SQRTN - 1), query(r2, 0, c2)));
}


// int main()
//
//
// read input
//
// preprocess()
//
// for each query:
//      query(l[i], r[i]);
