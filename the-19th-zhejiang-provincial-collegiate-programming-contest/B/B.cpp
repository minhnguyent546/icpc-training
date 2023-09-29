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
    string s;
    cin >> s;
    int n = (int) s.size();
    string ans = "";
    for (int i = 0; i < n; ++i) {
        ans += s[i];
        if (i >= 2 && s.substr(i - 2, 3) == "cjb") {
            ans += ',';
        }
    }
    cout << ans << '\n';

    return 0;
}
