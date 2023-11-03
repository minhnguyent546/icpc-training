#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		const int V = 71;
		vector<vector<int>> dp(n + 1, vector<int>(V + 1));
		dp[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= V; ++j) {
				for (int k = i + 1; k <= n; ++k) {
					int g = __gcd(arr[k - 1], j);
					dp[k][g] += dp[i][j];
					if (dp[k][g] >= MOD) dp[k][g] -= MOD;
				}
			}
		}
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			for (int g = 1; g <= V; ++g) {
				res = (res + 1LL * g * dp[i][g]) % MOD;
			}
		}
		cout << res << '\n';
	}
	return 0;
}
