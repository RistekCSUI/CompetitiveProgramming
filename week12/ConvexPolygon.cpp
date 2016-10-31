struct Point {
	int x, y;
	Point() { }
	Point(int x, int y): x(x), y(y) { }
};

long long cross(Point o, Point a, Point b) {
	return (long long) (a.x - o.x) * (b.y - o.y) - (long long) (b.x - o.x) * (a.y - o.y);
}

double area(vector<Point> v) {
	double ans = 0.0;
	for (int i = 0; i < (int) v.size(); ++i) {
		int nxt = (i + 1) % v.size();
		ans += cross(Point(0, 0), v[i], v[nxt]);
	}
	return fabs(ans) * 0.5;
}

double perimeter(vector<Point> v) {
	double ans = 0.0;
	for (int i = 0; i < (int) v.size(); ++i) {
		int nxt = (i + 1) % v.size();
		ans += hypot(v[i].x - v[nxt].x, v[i].y - v[nxt].y);
	}
	return ans;
}
