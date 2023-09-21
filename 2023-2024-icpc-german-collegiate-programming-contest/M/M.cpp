/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

vector<int> work(int a, int b) {
	vector<int> res = {a + b, a * b, a - b, b - a};
	if (b != 0 && a % b == 0) res.push_back(a / b);
	if (a != 0 && b % a == 0) res.push_back(b / a);
	return res;
}

bool check(int a, int b, int c, int d) {
	auto vals = work(a, b);
	for (int v : vals) {
		if (v == d) return true;
		auto tmp = work(v, c);
		for (int vv : tmp) {
			if (vv == d) {
				return true;
			}
		}
	}
	return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int d;
    cin >> d;
    const int LIMIT = 100;
    for (int a = 1; a <= LIMIT; ++a) {
    	for (int b = a + 1; b <= LIMIT; ++b) {
    		for (int c = b + 1; c <= LIMIT; ++c) {
    			set<int> nums{a, b, c, d};
    			if ((int) nums.size() != 4) continue;
    			if (!(check(a, b, c, d) || check(a, c, b, d) || check(b, c, a, d))) {
    				cout << a << ' ' << b << ' ' << c << '\n';
    				return 0;
    			}
    		}
    	}
    }

	return 0;
}
