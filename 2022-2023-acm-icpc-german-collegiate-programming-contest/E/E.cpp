/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

using Mat = vector<array<double, 2>>;

Mat mult(Mat a, Mat b) {
    Mat ans;
    ans.resize(2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

Mat pow(Mat a, long long n) {
    Mat res;
    res = {{1, 0}, {0, 1}};
    while (n > 0) {
        if (n & 1) res = mult(res, a);
        a = mult(a, a);
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.precision(17);
    cout << fixed;

    long long n;
    cin >> n;
    --n;
    if (n == 0) {
        cout << 100 << ' ' << 0 << '\n';
        return 0;
    }
    Mat M = {{1.0 / 2, 1.0 / 2}, {1, 0}};
    Mat T = pow(M, n - 1);
    double a = 100 * T[0][1];
    double b = 100 * T[0][0];
    cout << a << ' ' << b << '\n';

	return 0;
}
