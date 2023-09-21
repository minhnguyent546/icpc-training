/**            
 * author      minhnguyent546
 * created_at  Thursday, 2023-09-14 14:33:37
 **/           
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;

long long cost(const vector<int> &arr, int x) {
    long long res = 0;
    for (int v : arr) {
        res += min(abs(v), abs(x - v));
    }
    return res;
}

long long ternary_search(const vector<int> &arr) {
    if (arr.empty()) return INF_LL;
    int n = (int) arr.size();
    int l = arr[0], r = arr[n - 1];
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (cost(arr, mid) < cost(arr, mid + 1)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return cost(arr, l);
}   

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> neg, pos;
    for (int i = 0; i < n; ++i) {
    	int val;
    	cin >> val;
    	if (val <= 0) {
    		neg.push_back(val);
    	}
    	else {
    		pos.push_back(val);
    	}
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    long long neg_sum = -accumulate(neg.begin(), neg.end(), 0LL);
    long long pos_sum = accumulate(pos.begin(), pos.end(), 0LL);
    int x = (int) neg.size(), y = (int) pos.size();
    long long cost_neg = ternary_search(neg);
    long long cost_pos = ternary_search(pos);
    long long res;
    if (x == 0 || y == 0) {
        res = (y == 0 ? cost_neg : cost_pos);
    }
    else {
        res = min(cost_neg + pos_sum, cost_pos + neg_sum);
    }
    cout << res << '\n';

	return 0;
}
