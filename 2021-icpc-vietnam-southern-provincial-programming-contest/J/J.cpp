#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	vector<vector<int>> left(n, vector<int>(m));
	vector<vector<int>> right(n, vector<int>(m));
	vector<vector<int>> up(n, vector<int>(m));
	vector<vector<int>> down(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == '0') continue;
			left[i][j] = 1 + (j > 0 ? left[i][j - 1] : 0);
			up[i][j] = 1 + (i > 0 ? up[i - 1][j] : 0);
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (grid[i][j] == '0') continue;
			right[i][j] = 1 + (j + 1 < m ? right[i][j + 1] : 0);
			down[i][j] = 1 + (i + 1 < n ? down[i + 1][j] : 0);
		}
	}
	int best = -1;
	int u, v;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x = min({left[i][j], right[i][j], up[i][j], down[i][j]});
			if (x == 0) continue;
			if (best < x) {
				best = x;
				u = i;
				v = j;
			}
		}
	}
	if (best == -1) {
		cout << best << '\n';
		return 0;
	}
	cout << (best - 1) * 4 + 1 << '\n';
	cout << u + 1 << ' ' << v + 1 << '\n';
	return 0;
}