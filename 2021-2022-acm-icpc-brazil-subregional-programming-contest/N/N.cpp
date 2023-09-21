/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct Info {
	int year, rank, how_long;
};

struct Event {
	int l, r, rank, idx;
};

struct FT {
	int n;
	vector<int> tree;
	FT() {}
	FT(int _n): n(_n) {
		tree.resize(n);
	}
	void add(int i, int val) {
		while (i < n) {
			tree[i] += val;
			i |= (i + 1);
		}
	}
	int query(int i) {
		int res{};
		while (i >= 0) {
			res += tree[i];
			i = (i & (i + 1)) - 1;
		}
		return res;
	}
	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Y, n;
    cin >> Y >> n;
    vector<int> slots(Y);
    for (int i = 0; i < Y; ++i) {
    	cin >> slots[i];
    }
    vector<Info> info(n);
    for (int i = 0; i < n; ++i) {
    	cin >> info[i].year >> info[i].rank >> info[i].how_long;
    	--info[i].year;
    }
    vector<int> ans(n);
    vector<Event> events;
    for (int i = 0; i < n; ++i) {
    	if (slots[info[i].year] >= info[i].rank) continue;
    	events.push_back({info[i].year + 1, info[i].year + info[i].how_long, info[i].rank, i});
    }
    sort(events.begin(), events.end(), [](const auto &lhs, const auto &rhs) {
    	return lhs.rank > rhs.rank;
    });
    FT ft(Y);
    vector<int> order(Y);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
    	return slots[i] > slots[j];
    });
    int ptr = 0;
    for (const auto &[l, r, rank, idx] : events) {
    	while (ptr < Y && slots[order[ptr]] >= rank) {
    		ft.add(order[ptr], 1);
    		++ptr;
    	}
    	ans[idx] = ft.query(l, r);
    }
    for (int i = 0; i < n; ++i) {
    	cout << ans[i] << '\n';
    }

	return 0;
}
