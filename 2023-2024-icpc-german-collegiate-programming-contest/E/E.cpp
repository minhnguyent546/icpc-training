/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
#include <cctype>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    int n = (int) s.size();
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (s.find("sss") != string::npos) {
    	for (int i = 0; i < n; ++i) {
    		if (s[i] == 's') {
    			assert(i + 2 < n);
    			string ans1 = s.substr(0, i) + 'B' + s.substr(i + 2);
    			string ans2 = s.substr(0, i + 1) + 'B' + s.substr(i + 3);
    			cout << s << '\n';
    			cout << ans1 << '\n';
    			cout << ans2 << '\n';
    			return 0;
    		}
    	}
    }
    else if (s.find("ss") != string::npos) {
    	for (int i = 0; i < n; ++i) {
    		if (s[i] == 's' && s[i + 1] == 's') {
    			string ans = s.substr(0, i) + 'B' + s.substr(i + 2);
    			cout << s << '\n';
    			cout << ans << '\n';
    			return 0;
    		}
    	}
    }
    else {
    	cout << s << '\n';
    }

	return 0;
}
