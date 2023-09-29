#include <bits/stdc++.h>
#define ll long long
#define infInt (int)1e9 + 1
// #define infLL 0x3f3f3f3f3f3f
#define infLL (int)1e18
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define vtttt vector<vttt>
#define pii pair<int, int>
#define vpii vector<pii>
#define endl '\n'
#define all(a) a.begin(), a.end()
#define _sort(a) sort(all(a))
#define bsUp(a, x) upper_bound(all(a), x) - a.begin()
#define bsLow(a, x) lower_bound(all(a), x) - a.begin()
#define rev(a) reverse(all(a))
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define int ll
// #define in(a); ; 
// #define hi ;
// #include "/home/phamngocthi/cp/see.cpp"
using namespace std;

string s;
int q, n;
string per[2] = {"Putata", "Budada"};

struct Hash {
    int mod, base, n;
    string s;
    vt h, p;
    void init(string _s, int _mod, int _base) {
        mod = _mod, base = _base, s = _s;
        n = s.length();
        h.assign(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            h[i] = h[i - 1] * base + s[i - 1] - 'a' + 1, h[i] %= mod;
        }
        p.assign(n + 1, 1);
        for(int i = 1; i <= n; i++)
            p[i] = p[i - 1] * base % mod;
    }

    int getHash(int i, int j) {
        i++, j++;
        return (h[j] - h[i - 1] * p[j - i + 1] + mod * mod) % mod;
    }
};

bool isP(Hash &h1, Hash &h2, int l, int r) {
    return h1.getHash(l, r) == h2.getHash(h2.n - 1 - r, h2.n - 1 - l);
}

int bs(vpii &a, int l, int r) {
    int i = 0, j = a.size() - 1, res = -1;
    while(i <= j) {
        int m = (i + j) / 2;
        auto[_ll, rr] = a[m];
        if(_ll >= l) {
            res = m;
            j = m - 1;
        } else {
            i = m + 1;
        }
    } 
    return res;
}

bool check(int _ll, int rr, int l, int r) {
    return _ll >= l && _ll <= rr && rr <= r && (l - _ll == r - rr);
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> q >> s;
    string ss = s;
    rev(ss);
    int mod = (int)1e9 + 7, base = 311;
    Hash h1, h2;
    h1.init(s, mod, base);
    h2.init(ss, mod, base);
    vpii a;
    int l = 0;
    while(l + 1 < s.length() && s[l] == s[l + 1])
        l++;
    int r = l;
    while(r + 1 < s.length()) {
        while(r + 1 < s.length() && s[r + 1] == s[r - 1] && s[r + 1] != s[r]) {
            r++;
        }
        a.push_back({l, r});
        r++;
        l = r;
    }
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(isP(h1, h2, l, r)) {
            cout << per[1] << endl;
            continue;
        }
        int pos = bs(a, l, r);
        if(pos == -1) {
            cout << ((r - l + 1) % 2 == 0 ? per[1] : per[0]) << endl;
        } else {
            bool ok = false;
            auto[_ll, rr] = a[pos];
            if((rr - _ll + 1) % 2 == 0) {
                ok = check(_ll, rr, l, r);
            } else {
                ok = (check(_ll + 1, rr, l, r) || check(_ll, rr - 1, l, r));
            }
            if(ok) {
                cout << per[1] << endl;
            } else {
                cout << ((r - l + 1) % 2 == 0 ? per[1] : per[0]) << endl;
            }
        }
    }
}
