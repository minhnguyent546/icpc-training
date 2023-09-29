/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int N = (int) 1e3;
char grid[N][N];

vector<string> M = {
    "######",
    "##..##",
    "#....#",
    "#....#",
    "##..##",
    "######",
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    const int A = 146, B = 100;
    int covered = 0, empty = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> grid[r][c];
            covered += (grid[r][c] == '#');
        }
    }
    int nM = (int) M.size(), mM = (int) M[0].size();
    for (int r = 0; r <= n - nM; ++r) {
        for (int c = 0; c <= m - mM; ++c) {
            bool good = true;
            for (int i = 0; i < nM && good; ++i) {
                for (int j = 0; j < mM; ++j) {
                    if (grid[r + i][c + j] != M[i][j]) {
                        good = false;
                        break;
                    }
                }
            }
            if (good) {
                empty += 12;
            }
        }
    }
    empty /= 12;
    int x = empty * 100 - covered;
    assert(x % 54 == 0);
    x /= 54;
    int y = empty - 2 * x;
    cout << x << ' ' << y << '\n';
    return 0;
}
