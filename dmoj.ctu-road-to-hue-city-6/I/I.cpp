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
    int s, t;
    cin >> s >> t;
    int res = 0;
    for (int a = 0; a <= s; ++a) {
        for (int b = 0; b <= s; ++b) {
            for (int c = 0; c <= s - a - b; ++c) {
                if (a * b * c <= t) {
                    ++res;
                }
            }
        }
    }
    cout << res << '\n';

	return 0;
}
