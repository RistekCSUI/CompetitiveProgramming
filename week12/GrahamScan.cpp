// Implementation of Graham Scan algorithm

struct Point {
	int x, y;
	Point() { }
	Point(int x, int y): x(x), y(y) { }
	bool operator < (const Point& other) const {
		// priority: lowest point
		// tie: rightmost point
		return (y == other.y) ? (x > other.x) : (y < other.y);
	}
};

Point o;

long long cross(Point o, Point a, Point b) {
	return (long long) (a.x - o.x) * (b.y - o.y) - (long long) (a.y - o.y) * (b.x - o.x);
}

bool cmp(Point a, Point b) {
	long long c = cross(o, a, b);
	if (c == 0LL)
		return hypot(a.x - o.x, a.y - o.y) < hypot(b.x - o.x, b.y - o.y);
	return c > 0;
	// Angle comparison
	// return (atan2(a.y - o.y, a.x - o.x) - atan2(b.y - o.y, b.x - o.x)) < 0;
}

vector<Point> convexHull(vector<Point> v) {
	vector<Point> ret;
	int st = 0;
	// find pivot
	for (int i = 1; i < (int) v.size(); ++i) {
		if (v[i] < v[st]) {
			st = i;
		}
	}
	swap(v[st], v[0]);
	o = v[0];
	// sort the remaining points
	sort(v.begin() + 1, v.end(), cmp);
	ret.push_back(v.back());
	ret.push_back(o);
	int k = 2;
	for (int i = 1; i < (int) v.size(); ++i) {
		while (cross(ret[k - 2], ret[k - 1], v[i]) < 0) {
			ret.pop_back();
			--k;
		}
		ret.push_back(v[i]);
		++k;
	}
	return ret;
}
