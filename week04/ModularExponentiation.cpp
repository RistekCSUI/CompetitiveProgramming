const int MOD = 1000000007;

int modExp(int base, int power) {
	if (power == 0) return 1;
	int x = modExp(base, power / 2);
	x = ((long long) x * x) % MOD;
	if (power % 2 == 1) x = ((long long) x * base) % MOD;
	return x;
}

int iterativeModExp(int base, int power) {
	int x = 1;
	while (p) {
		if (p & 1) x = ((long long) x * base) % MOD;
		base = ((long long) base * base) % MOD;
		p >>= 1;
	}
	return x;
}