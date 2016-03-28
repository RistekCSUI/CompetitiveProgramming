#include <algorithm>

using namespace std;

template <class T>
struct BinaryHeap {
	// max_heap

	vector<T> heap;

	BinaryHeap() {}

	BinaryHeap(vector<T> arr) {
		// heapify
		heap = vector<T>(arr.begin(), arr.end());
		for (int i = (heap.size() >> 1); i >= 0; --i) {
			percolateDown(i);
		}
	}

	void percolateDown(int node) {
		int left = 2 * node + 1, right = 2 * node + 2;
		int pos = node;
		if (left < heap.size() && heap[left] > heap[pos]) {
			pos = left;
		}
		if (right < heap.size() && heap[right] > heap[pos]) {
			pos = right;
		}
		if (pos != node) {
			swap(heap[pos], heap[node]);
			percolateDown(pos);
		}
	}

	void percolateUp(int node) {
		while (node > 0 && (heap[node] > heap[node >> 1])) {
			swap(heap[node], heap[node >> 1]);
			node >>= 1;
		}
	}

	void push(T v) {
		heap.push_back(v);
		percolateUp(heap.size() - 1);
	}

	T top() {
		return heap[0];
	}

	void pop() {
		heap[0] = heap.back();
		heap.pop_back();
		percolateDown(0);
	}

	bool empty() {
		return heap.size() == 0;
	}
};

int main() {
	BinaryHeap<pair<int, int> > pq = BinaryHeap<pair<int, int> >();
	pq.push(make_pair(3, 1));
	pq.push(make_pair(3, 3));
	pq.push(make_pair(8, 7));
	while (!pq.empty()) {
		pair<int, int> u = pq.top();
		pq.pop();
		printf("%d %d\n", u.first, u.second);
	}

	vector<long long> v={2, 3, -100, 1 << 3, 5};
	BinaryHeap<long long> arr = BinaryHeap<long long>(v);
	while (!arr.empty()) {
		long long u = arr.top();
		arr.pop();
		printf("%lld\n", u);
	}
}