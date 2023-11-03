/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const double PI = acos(-1);
const double eps = 1e-9;
const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;
using Point = pair<double, double>;

Point add(Point A, Point B) {
	return Point(A.first + B.first, A.second + B.second);
}

Point mult(Point A, double k) {
	return Point(A.first * k, A.second * k);
}

Point rotate(Point A, double deg) {
	return Point(- A.second * sin(deg * PI / 180), A.first * sin(deg * PI / 180));
}

Point middle(Point A, Point B) {
	return Point((A.first + B.first) / 2, (A.second + B.second) / 2);
}

Point center(Point A, Point B) {
	Point mid = middle(A, B);
	return Point(2 * mid.first, 2 * mid.second);
}

void printResult(vector<Point> result) {
	cout << result.size() - 1 << '\n';
	for (auto [x, y]: result) {
		cout << x << ' ' << y << '\n';
	}
}

double distance(Point A, Point B) {
	return sqrt((A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cout.precision(10); cout << fixed;
    int tt; cin >> tt;
    while (tt--) {
    	int d1, d2; cin >> d1 >> d2;

    	Point s(cos(PI * d1 / 180), sin(PI * d1 / 180));
    	Point t(cos(PI * d2 / 180), sin(PI * d2 / 180));

    	vector<Point> result;
    	result.emplace_back(s);
    	if (d1 > d2) d2 += 360; // d2 > d1

    	if (d1 == d2) {
			// zero point
    	} else if (d2 - d1 <= 90 || d2 - d1 >= 270) {
    		// 2 points
	    	result.emplace_back(center(s, t));
		} else {
			// check 3 points
			double deg; 
			if (d2 - d1 < 180) 
				deg = 90; // d1 -> d2
			else 
				deg = -90; // d2 <- d1

			// s -> a .. b -> t
			Point a = add(s, rotate(s, deg)); 
			Point b = add(t, rotate(t, -deg));

			if (distance(a, b) <= 1.0) { // ab <= 1.0 
    			result.emplace_back(a); // s -> a -> c -> t

				Point mid = middle(a, t);
				Point u(t.first - a.first, t.second - a.second);
				double d = distance(a, t);
				u = rotate(u, -deg);
				u = mult(u, sqrt(1.0 - d * d / 4.0) / d);
				
				result.emplace_back(add(mid, u));
			} else {
				// 4 points
				Point ss = rotate(s, deg);
				result.emplace_back(center(s, ss));
				result.emplace_back(ss);
				result.emplace_back(center(ss, t));
			}
    	}

    	if (result.size() != 1) result.emplace_back(t);
    	printResult(result);
    }

	return 0;
}
