#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);
    vector<int> evens;
    vector<int> odds;
    for (int v : arr) {
        if (v % 2 == 0) evens.push_back(v);
        else odds.push_back(v);
    }
    string s;
    cin >> s;
    for (char ch : s) {
        if (ch == '0') {
            vector<int> new_evens;
             for (int v : evens) {
                v /= 2;
                sum -= v;
                if (v & 1) {
                    odds.push_back(v);
                }
                else {
                    new_evens.push_back(v);
                }
            }
            evens.swap(new_evens);
        } else {
            sum -= (int) odds.size();
            for (int v : odds) {
                if (v > 1) {
                    evens.push_back(v - 1);
                }
            }
            odds.clear();
        }
        cout << sum << '\n';
    }
    return 0;
}
