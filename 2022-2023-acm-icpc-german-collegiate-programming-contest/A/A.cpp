/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

#define int long long
using point = pair<int, int>;

point rotate(point a) {
    return point(-a.second, a.first);
}

point mult(point a, int t, int k) {
    return point(a.first * t / k, a.second * t / k);
}

point add(point a, point b) {
    return point(a.first + b.first, a.second + b.second);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);


    int a, b; cin >> a >> b;
    a--;
    b--;

    int count = 0;

    for (int x0 = 0; x0 < a; x0++) {
        int y0 = sqrt(a * a - x0 * x0);

        while (y0 * y0 + x0 * x0 < a * a)
            y0++;

        while (y0 * y0 + x0 * x0 > a * a)
            y0--;

        if (y0 * y0 + x0 * x0 != a * a) {
            continue;
        }

        point u(x0, y0);

        point n = rotate(u);
        if (n.first * b % a != 0 || n.second * b % a != 0)
            continue;

        if (x0 == y0)
            count+=1;
        else count +=2;

    }

    cout << (a == b ? count / 2: count);
	return 0;
}
