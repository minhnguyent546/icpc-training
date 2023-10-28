#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int res = -INF;
	for (int i = 0, cur = 0, largest = -INF; i < n; ++i) {
		cur += arr[i];
		largest = max(largest, arr[i]);
		res = max(res, cur - largest);
		if (cur < 0) {
			cur = 0;
			largest = -INF;
		}
	}
	cout << res << '\n';
	return 0;
}