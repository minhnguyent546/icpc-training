#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

#define double long double

const double PI = acos(-1);

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.precision(17);
    cout << fixed;
    double h, d;
    cin >> h >> d;
    double x = 34 * PI / 180;
    double alpha = atan(d / (2 * h));
    double r = d * cos(alpha) * cos(x) / (2 * cos((x - alpha)));
    double volume = 1.0 / 3 * PI * r * r * h;
    cout << volume << '\n';
    return 0;
}
