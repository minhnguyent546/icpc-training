#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

const char minchar = 'a';
const int ALPHABET = 26;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string best = "";
    string pref = "";
    for (int i = 0; i < n; ++i) {
        pref += s[i];
        string e(i + 1, ' ');
        vector<int> freq(ALPHABET);
        vector<int> distinct(i + 1);
        vector<int> last(ALPHABET, -1);
        for (int j = i, d = 0; j >= 0; --j) {
            char ch = pref[j];
            freq[ch - minchar]++;
            if (freq[ch - minchar] == 1) ++d;
            distinct[j] = d;
            if (last[ch - minchar] == -1) {
                last[ch - minchar] = j;
            }
        }
        for (int j = 0; j <= i; ++j) {
            int p = last[pref[j] - minchar];
            int num = (p < i ? distinct[p + 1] : 0);
            e[j] = (char) (num + minchar);
        }
        // cerr << i << ' ' << e << '\n';
        if (best == "" || best < e) {
            best = e;
        }
    }
    cout << best << '\n';

    return 0;
}
