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
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
    	arr[i] = s[i] - '0';
    }
    if (n == 1) {
    	cout << (arr[0] + 1) << '\n';
    	return 0;
    }
    int id = 1;
    while(id < n && arr[id] == arr[0])
    	id++;
    if(id == n || arr[id] >= arr[0])
    	cout << n * arr[0] + (9 - arr[0] + 1) * (n - 1) << '\n';
    else 
   		cout << n * (arr[0] - 1) + (9 - arr[0] + 2) * (n - 1) << '\n';
	return 0;
}
