#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF (long long)1e18

typedef pair<int, int> point;

struct Line {
	point n;
	int c;
	// n(a, b) => ax + by + c = 0; c = -ax-by
	Line(point& a, point& b) {
		n.first = (a.second - b.second);
		n.second = (b.first - a.first);
		int g = __gcd(n.first, n.second);
		n.first /= g;
		n.second /= g;
		c = - n.first * a.first - n.second * a.second;
	}

	bool contains(point& a) {
		return n.first * a.first + n.second * a.second + c == 0;
	}
};

bool can(int k, vector<point> points) {
	if (points.size() <= k) return true;
	if (k == 1) {
		Line l(points[0], points[1]);
		for (int i = 2; i < points.size(); i++) {
			if (!l.contains(points[i]))
				return false;
		}
		return true;
	} else {
		bool res = false;
		for (int i = 0; i < k + 1; i++)
			for (int j = i + 1; j < k + 1; j++) {
				Line l(points[i], points[j]);
				vector<point> rem;
				for (int k = 0; k < points.size(); k++) {
					if (!l.contains(points[k]))
						rem.push_back(points[k]);
				}

				res |= can(k - 1, rem);
			}

		return res;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<point> points(n);

	for (int i = 0; i < n; i++)
		cin >> points[i].first >> points[i].second;

	cout << (can(3, points) ? "possible" : "impossible") << '\n';

}
