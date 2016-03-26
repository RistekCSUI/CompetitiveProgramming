#include <vector>
using namespace std;

// Get the least significant one from an integer
#define LSONE(x) (x & -x)

// Define the range of indices
#define N 200005

template <class T>
struct FenwickTree // or you can name it BIT
{
	vector<T> arr;

	FenwickTree()
	{
		arr.resize(N);
		fill(arr.begin(), arr.end(), 0);
	}

	void update(int pos, T val)
	{
		// This assumes that pos > 0
		// if the case is that pos is 0-indexed, uncomment the line below
		//++pos;
		for (; pos < N; pos += LSONE(pos))
			arr[pos] += val; // This assumes that T implemented the += operator
		return ;
	}

	T query(int pos)
	{
		// This assumes that pos > 0
		// if the case is that pos is 0-indexed, uncomment the line below
		//++pos;
		T result = 0;
		for (; pos; pos -= LSONE(pos))
			result += arr[pos];
		return result;
	}

	T query(int L, int R)
	{
		// [L, R] = [1, R] - [1, L)
		return query(R) - query(L - 1);
	}
};

// Use it by:
// FenwickTree<YOUR_DATA_TYPE_HERE>
FenwickTree<int> ft;
