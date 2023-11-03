#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;
#undef LOCAL
#ifndef LOCAL
#define cerr if (false) cerr
#endif

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	vector<vector<int>> g(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			g[i][j] = __gcd(arr[i], arr[j]);
		}
	}
	vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(n)));
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[i] || g[i][j] != 1) continue;
			dp[i][j][1] = 1;	
		}
	}
	for (int k = 2; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				for (int h = j - 1; h > i; --h) {
					if (g[h][j] == 1) {
						dp[i][j][k] += dp[i][h][k - 1];
						dp[i][j][k] %= 2023;
					}
				}
			}
		}
	}
	int maxv = *max_element(arr.begin(), arr.end());
	vector<vector<map<int, long long>>> f(n, vector<map<int, long long>>(maxv + 1));
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (arr[j] < arr[i]) continue;
				f[k][arr[i]][arr[j]] += dp[i][j][k];
				f[k][arr[i]][arr[j]] %= 2023;
			}
		}
	}
	int q;
	cin >> q;
	for (int w = 0; w < q; ++w) {
		int a, b, k;
		cin >> a >> b >> k;
		assert(1 <= k && k <= n);
		// --k;
		if (k == n) {
			cout << 0 << '\n';
			continue;
		}
		cout << f[k][a][b] % 2023 << '\n';
	}
	return 0;
}
