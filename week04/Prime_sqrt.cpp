bool isPrime(int n) {
	for (int i = 2; (long long) i * i <= n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

vector<int> factorize(int n) {
	vector<int> res;
	for (int i = 2; (long long) i * i <= n; ++i) {
		while (n % i == 0) {
			res.push_back(i);
			n /= i;
		}
	}
	if (n > 1) res.push_back(n);
	return res;
}