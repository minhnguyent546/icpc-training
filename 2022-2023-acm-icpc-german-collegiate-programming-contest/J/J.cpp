/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

vector<pair<char, int>> a;
string h = "hdcs";
map<char, int> uuTien;

bool cmp(pair<char,int> x, pair<char,int> y) {
    if(x.first == y.first)
        return x.second < y.second;
    return uuTien[x.first] < uuTien[y.first];
}

int lis(vector<int> &a) {
    int n = (int) a.size();
    vector<int> dp;
    for (int v : a) {
        auto it = lower_bound(dp.begin(), dp.end(), v) - dp.begin();
        if (it == (int) dp.size()) {
            dp.push_back(v);
        }
        else {
            dp[it] = v;
        }
    }
    return n - (int) dp.size();
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++) {
        a.push_back({s[i], i});
    }
    sort(h.begin(), h.end());
    int ans = n;
    do {
        uuTien.clear();
        for (int i = 0; i < 4; ++i) {
            uuTien[h[i]] = i;
        }
        sort(a.begin(), a.end(), cmp);
        vector<int> index;
        for(auto x : a)
            index.push_back(x.second);
        ans = min(ans, lis(index));

    } while (next_permutation(h.begin(), h.end()));
    cout << ans;
	return 0;
}
