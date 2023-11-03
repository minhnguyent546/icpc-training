#include <bits/stdc++.h>

using namespace std;

int y, z;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	cin >> y >> z;
	for(int i = 0; i < n; i++) {
		a[i] = abs(a[i] - z);
	}
	sort(a.begin(), a.end());
	long long timeY = abs(y - z);
	long long timeP = 0;
	int cnt = 0;
	for(int x : a) {
		timeP += x;
		if(timeP < timeY)
			cnt++;
		else
			break;
	}
	cout << cnt;
	return 0;
}