/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    // cin.tie(nullptr)->sync_with_stdio(false);
    auto ask = [&](long long a) {
        cout << '?' << ' ' << a << endl;
        long long r;
        cin >> r;
        return r;
    };
    long long a = 1;
    while (true) {
        long long r = ask(a);
        if (r < a / 2 || (a == 1 && r == 0)) {
            cout << '!' << ' ' << a - r << '\n';
            return 0;
        }
        a *= 2;
    }
	return 0;
}
