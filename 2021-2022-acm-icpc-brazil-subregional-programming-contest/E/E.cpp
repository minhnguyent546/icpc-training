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
// #define int ll
// #define in(a); ; 
// #define hi ;
// #include "/home/phamngocthi/cp/see.cpp"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vpii a;
    int type = -1;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
        if(type == -1)
            type = y;
    }
    queue<int> q;
    int t = 0;
    for(int i = 0; i < n; i++) {
        auto[x, y] = a[i];
        if(x <= t) {
            if(y == type) {
                t = x + 10;
            } else {
                q.push(x);
            }
        } else {
            int top = -1;
            while(!q.empty()) {
                top = q.front();
                q.pop();
            }
            if(top != -1) {
                t += 10;
                type = 1 - type;
                i--;
            } else {
                t = x + 10;
                type = y;
            }
        }
        // cout << "t = " << t << endl;
        // cout << "i = " << i << endl;
    }
    int top = -1;
    while(!q.empty()) {
        top = q.front();
        q.pop();
    }
    // cout << "top = " << top << endl;
    if(top != -1) {
        t += 10;
    }
    cout << t;
    return 0;
}
