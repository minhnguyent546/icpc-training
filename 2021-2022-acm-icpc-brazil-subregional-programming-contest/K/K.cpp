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
    int T, D, M;
    cin >> T >> D >> M;
    vector<int> arr(M + 2);
    for (int i = 1; i <= M; ++i) {
    	cin >> arr[i];
    }
    arr[M + 1] = D;
    for (int i = 1; i <= M + 1; ++i) {
    	// cerr << i << ' ' << arr[i] - arr[i - 1] << '\n';
    	if (arr[i] - arr[i - 1] >= T) {
    		cout << "Y\n";
    		return 0;
    	}
    }
    cout << "N\n";

	return 0;
}
