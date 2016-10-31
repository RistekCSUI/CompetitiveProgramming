// Implementation of Andrew's Monotone Chain algorithm

struct Point {
	int x, y;
	Point() { }
	Point(int x, int y): x(x), y(y) { }
	bool operator < (const Point& other) const {
		return x < other.x;
	}
};

long long cross(Point o, Point a, Point b) {
	return (long long) (a.x - o.x) * (b.y - o.y) - (long long) (a.y - o.y) * (b.x - o.x);
}

vector<Point> convexHull(vector<Point> v) {
	vector<Point> ret;
	sort(v.begin(), v.end());
	int k = 0;
	for (int i = 0; i < n; ++i) {
		while (k > 1 && cross(ret[k - 2], ret[k - 1], v[i]) > 0) {
			--k;
			ret.pop_back();
		}
		ret.push_back(v[i]);
		++k;
	}
	for (int i = n - 2, t = k; i >= 0; --i) {
		while (k > t && cross(ret[k - 2], ret[k - 1], v[i]) > 0) {
			--k;
			ret.pop_back();
		}
		ret.push_back(v[i]);
		++k;
	}
	return ret;
}
