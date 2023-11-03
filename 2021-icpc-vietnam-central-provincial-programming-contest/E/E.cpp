#include <bits/stdc++.h>

using namespace std;

#define int long long

using point = pair<int, int>;

int cross(point a, point b) {
	return a.first * b.second - a.second * b.first;
}

point vec(point a, point b) {
	return point(a.first - b.first, a.second - b.second);
}

bool check(vector<point>& points, vector<int> perm) {
	perm.push_back(perm[0]);
	perm.push_back(perm[1]);
	int last = cross(vec(points[perm[1]], points[perm[0]]), vec(points[perm[1]], points[perm[2]]));
	for (int i = 1; i < (int) points.size(); i++) {
		int cur = cross(vec(points[perm[i + 1]], points[perm[i]]), vec(points[perm[i + 1]], points[perm[i + 2]]));

		if (((cur ^ last) < 0) || cur == 0 || last == 0) return false;
	}
	return true;
}

void solve() {
	vector<point> points(4);
	for (int i = 0; i < 4; i++)
		cin >> points[i].first >> points[i].second;

	bool can = false;
	vector<int> perm = {0, 1, 2, 3};

	do {
		if (check(points, perm)) {
			can = true;
		}

	} while (next_permutation(perm.begin(), perm.end()));

	cout << (can ? "YES" : "NO") << '\n';
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int tt; cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}
