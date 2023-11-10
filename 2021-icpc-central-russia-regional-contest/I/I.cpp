#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int magic(long long n) {
    int cnt = 0;
    while (n > 1) {
        if (n % 2 == 0) n /= 2;
        else {
            n = n * 3 + 1;
        }
        ++cnt;
    }
    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long L;
    int w;
    cin >> L >> w;
    long long R = L + w - 1;
    vector<int> res(R - L + 1);
    for (long long i = L; i <= R; ++i) {
        long long x = magic(i);
        res[i - L] = x;
    }
    int max_f = 0;
    int prev = 0;
    int cur_f = 0;
    int cur_prev = 0;
    for (int i = 0; i < w; ++i) {
        if (i == 0 || res[i] == res[i - 1]) {
            ++cur_f;
        }
        else {
            cur_f = 1;
            cur_prev = i;
        }
        if (cur_f > max_f) {
            max_f = cur_f;
            prev = cur_prev;
        }
    }
    cout << max_f << ' ' << prev + L << '\n';

    return 0;
}
