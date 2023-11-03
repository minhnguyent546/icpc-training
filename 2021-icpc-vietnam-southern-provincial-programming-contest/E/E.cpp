#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.precision(17);
	cout << fixed;

	double a, h;
	cin >> a >> h;
	double x = (700 - 8 * a) / (1200 - 12 * a);
	double y;
	if (x < 1.0 / 6 || x > 1.0 / 3) {
		y = 0;
	}
	else {
		y = (1 - x) * ((600 - 6  * a) * x + 2 * a - 100);
	}
	double b = h * y;
	cout << max({5 * a / 6 * h, 200 * h / 3, b}) << '\n';
	return 0;
}
