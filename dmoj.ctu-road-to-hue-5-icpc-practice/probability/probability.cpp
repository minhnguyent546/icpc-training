/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    int n, a, b;
    cin >> n >> a >> b;
    const int side = 6;
    vector<long double> dp(n * side + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
	    vector<long double> next_dp(n * side + 1);
    	for (int j = 1; j <= n * side; ++j) {
	    	for (int k = 1; k <= min(side, j); ++k) {
		    	next_dp[j] += dp[j - k] / side;
	    	}
	    }
	    dp.swap(next_dp);
	}
	long double tot = 0;
	for (int i = a; i <= b; ++i) {
		tot += dp[i];
	}
	cout << tot << '\n';
	return 0;
}
