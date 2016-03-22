bitset<1000001> p;
vector<int> prime;

bool isPrime_1(int n) {
	return p[n];
}

bool isPrime(long long n) {
	for (int i = 0; (long long) prime[i] * prime[i] <= n; ++i) {
		if (n % prime[i] == 0)
			return false;
	}
	return true;
}

void sieve() {
	for (int i = 2; i <= 1000000; ++i)
		p[i] = 1;
	for (int i = 2; i <= 1000000; ++i) {
		if (p[i]) {
			for (int j = i * 2; j <= 1000000; j += i)
				p[j] = 0;
		}
	}
}

