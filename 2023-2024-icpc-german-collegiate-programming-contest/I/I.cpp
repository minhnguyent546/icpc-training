/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    set<int> es;
    for(int i = 1; i <= n - 1; i++) {
    	for(int j = a[i] + 1; j <= a[i + 1] - 1; j++) {
    		es.insert(j);
    	}
    }
    int t = a[n] + 1;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
    	int cur;
    	cin >> cur;
    	auto it = es.upper_bound(a[cur]);
    	if(it != es.end()) {
    		es.insert(a[cur]);
    		cout << *it << '\n';
    		a[cur] = *it;
    		es.erase(it);
    	} else {
    		es.insert(a[cur]);
    		cout << t << '\n';
    		a[cur] = t;
    		t++;
    	}
    }

	return 0;
}
