/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    multiset<int> xors, vals;
    int q;
    cin >> q;
    for (int w = 0; w < q; ++w) {
        int op, x;
        cin >> op;
        if (op < 3) cin >> x;
        if (op == 1) {
            auto left = vals.lower_bound(x);
            auto right = left;
            if (left == vals.begin() && right == vals.end()) {
                vals.insert(x);
                continue;
            }
            if (left != vals.begin() && right != vals.end()) {
                xors.erase(xors.find(*(prev(left)) ^ *right));
            }
            if (left != vals.begin()) {
                xors.insert(*(prev(left)) ^ x);
            }
            if (right != vals.end()) {
                xors.insert(x ^ *right);
            }
            vals.insert(x);
        }
        else if (op == 2) {
            vals.erase(vals.find(x));
            auto left = vals.lower_bound(x);
            auto right = left;

            if (left != vals.begin() && right != vals.end()) {
                xors.insert(*(prev(left)) ^ *right);
            }
            if (left != vals.begin()) {
                --left;
                xors.erase(xors.find(*left ^ x));
            }
            if (right != vals.end()) {
                xors.erase(xors.find(x ^ *right));
            }
        }
        else if (op == 3) {
            assert(!xors.empty());
            cout << *xors.begin() << '\n';
        }
        else assert(false);
    }
    // important: for non-negative integers a < b < c: min(a ^ b, b ^ c) < a ^ c
    return 0;
}
