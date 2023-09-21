/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

const char minchar = '0';
string add(string a, string b) {
    int n = (int) a.size(), m = (int) b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int sz = max(n, m);
    vector<int> res(sz + 1);
    for (int i = 0; i < sz; ++i) {
        int x = (i < n ? a[i] - minchar : 0);
        int y = (i < m ? b[i] - minchar : 0);
        res[i] = x + y;
    }
    for (int i = 0; i < sz; ++i) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
    string ans = "";
    for (int i = 0; i < sz; ++i) {
        ans += (char) (res[i] + minchar);
    }
    if (res.back()) ans += (char) (res.back() + minchar);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int sides[] = {4, 6, 8, 12, 20};
    vector<int> num(5);
    int n = 5;
    for (int i = 0; i < 5; ++i) {
    	cin >> num[i];
    }
    const int S = 1003;
    vector<string> dp(S, "0");
    dp[0] = "1";
    for (int i = 0; i < n; ++i) {
    	int side = sides[i];
    	for (int k = 0; k < num[i]; ++k) {
			vector<string> next_dp(S, "0");
			for (int val = 0; val < S; ++val) {
				if (dp[val] == "0") continue;
	    		for (int j = 1; j <= side; ++j) {
    				next_dp[val + j] = add(next_dp[val + j], dp[val]);
    			}
    		}
    		dp.swap(next_dp);
    	}
    }
    vector<int> order(S);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        if (dp[i].size() != dp[j].size()) {
            return dp[i].size() > dp[j].size();
        }
        return dp[i] > dp[j];
    });
    for (int i = 0; i < S; ++i) {
    	if (dp[order[i]] == "0") break;
    	cout << order[i] << ' ';
    }
    cout << '\n';
	return 0;
}
