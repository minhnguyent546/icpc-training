/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int l, w, n;
vector<vector<char>> a;

void color(int i1, int j1, int i2, int j2, char c) {
    for(int i = i1; i <= i2; i++)
        for(int j = j1; j <= j2; j++)
            a[i][j] = c;
}

void solve(int deli, int delj) {
    char c = 'A';
    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= w; j++) {
            if(a[i][j] == ' ') {
                color(i, j, i + deli, j + delj, c);
                c++;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> l >> w >> n;
    a.assign(l + 1, vector<char>(w + 1, ' '));
    if(l * w % n != 0) {
        cout << "impossible\n";
    } else {
        bool ok = false;
        int m = l * w / n;
        for(int i = 1; i <= m; i++) {
            if(m % i)
                continue;
            int j = m / i;
            if(l % i == 0 && w % j == 0) {
                int deli = l / (l / i) - 1, delj = w / (w / j) - 1;
                solve(deli, delj);
                ok = true;
                break;
            }
        }
        if(ok == false)
            cout << "impossible\n";
        else {
            for(int i = 1; i <= l; i++) {
                for(int j = 1; j <= w; j++) {
                    cout << a[i][j];
                }
                cout << endl;
            }
        }
    }

	return 0;
}
