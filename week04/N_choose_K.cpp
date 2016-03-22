/*

n choose k

nCk mod m 

   n!
--------   % m
(n-k)!k!


(n! / (n-k)! / k!) % m = (n! * inv((n-k)!) * inv((k!))) % m

*/

const int MOD = 1000000007;

int fact[1000001], inv[1000001];

void preprocess() {
	fact[0] = 1;
	for (int i = 1; i <= 1000000; ++i) {
		fact[i] = ((long long) fact[i - 1] * i) % MOD;
		inv[i] = modExp(fact[i], MOD - 2);
	}
}

// N choose K = C(N, K)
int C(int N, int K) {
	return (((long long) fact[N] * inv[N - K]) % MOD * inv[K]) % MOD;
}