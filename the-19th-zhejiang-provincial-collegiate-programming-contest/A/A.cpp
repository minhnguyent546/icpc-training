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
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a == b) {
            cout << 0 << '\n';
        } else if(a < b) {
            if((b - a) % 2 == 1) {
                cout << "1\n";
            } else {
                cout << (((b - a) / 2) % 2 == 1 ? "2\n" : "3\n");
            }
        } else {
            if((a - b) % 2 == 0) {
                cout << "1\n";
            } else {
                cout << "2\n";
            }
        }
    }

    return 0;
}
