#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

bool check(vector<string> &a, int v, int k) {
	int n = (int)a.size();
	int m = (int)a[0].size();
	vector<vector<bool>> used(n, vector<bool>(m, false));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] != 'x' || used[i][j])
				continue;
			k--;
			if (k < 0) return false;
			for(int t = j; t <= min(j + 2 * v, m - 1); t++) {
				if (a[i][t] == '#') break;
				else used[i][t] = true;
			}
		}
	}
	return true;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0, r = m, ans = m + 1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if (check(a, mid, k)) {
			ans = min(ans, mid);
			r = mid - 1;
		} else l = mid + 1;
	}
	if (ans == m + 1) 
		cout << -1;
	else cout << ans;
	return 0;
}
