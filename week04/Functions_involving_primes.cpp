#include <bitset>
#include <vector>

using namespace std;

bitset<1000001> p;
vector<int> prime;

bool isPrime_1(int n)
{
	return p[n];
}

bool isPrime(long long n)
{
	for (int i = 0; (long long) prime[i] * prime[i] <= n; ++i)
	{
		if (n % prime[i] == 0)
			return false;
	}
	return true;
}

void sieve()
{
	for (int i = 2; i <= 1000000; ++i)
		p[i] = 1;
	for (int i = 2; i <= 1000000; ++i)
	{
		if (p[i])
		{
			prime.push_back(i);
			for (int j = i * 2; j <= 1000000; j += i)
				p[j] = 0;
		}
	}
}

int numberOfDivisors(int n)
{
	int ans = 1;
	for (int i = 0; i < prime.size() && (long long) prime[i] * prime[i] <= n; ++i)
	{
		int cnt = 1;
		while (n % prime[i] == 0)
		{
			n /= prime[i];
			++cnt;
		}
		ans *= cnt;
	}
	if (n > 1)
		ans *= 2;
	return ans;
}

int sumOfDivisors(int n)
{
	int ans = 1;
	for (int i = 0; i < prime.size() && (long long) prime[i] * prime[i] <= n; ++i)
	{
		int v = prime[i];
		while (n % prime[i] == 0)
		{
			n /= prime[i];
			v *= prime[i];
		}
		ans *= (v - 1) / (prime[i] - 1);
	}
	if (n > 1) ans *= (n * n - 1) / (n - 1);
	return ans;
}

int eulerPhi(int n)
{
	// calculate the number of natural numbers <= n which are relatively prime with n

	int ans = n;
	for (int i = 0; i < prime.size() && (long long) prime[i] * prime[i] <= n; ++i)
	{
		if (n % prime[i] == 0)
		{
			ans -= ans / prime[i];
			while (n % prime[i] == 0)
			{
				n /= prime[i];
			}
		}
	}
	if (n > 1) --ans;
	return ans;
}