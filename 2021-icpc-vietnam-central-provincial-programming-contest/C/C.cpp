#include <bits/stdc++.h>

using namespace std;

#define double long double

struct item {
    int left, right;
    double x, value;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cout.precision(17); cout << fixed;

    int n; cin >> n;
    vector<double> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<double> pref(n + 1), pref2(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
        pref2[i] = pref2[i - 1] + a[i] * a[i];
    }

    auto get = [&](int left, int right) {
        assert(left <= right);
        return pref[right] - pref[left - 1];
    };


    auto get2 = [&](int left, int right) {
        assert(left <= right);
        return pref2[right] - pref2[left - 1];
    };

    auto calc = [&](int left, int right) {
        assert(left <= right);
        return get(left, right) / (right - left + 1);
    };

    auto calcValue = [&](int left, int right) {
        assert(left <= right);
        double x = calc(left, right);
        return get2(left, right) - 2 * x * get(left, right) + (right - left + 1) * x * x;
    };

    vector<item> items;

    items.push_back({1, 1, a[1], 0.0});

    for (int i = 2; i <= n; i++) {
        item cur = {i, i, a[i], 0.0};
        do {
            item last = items.back();

            item merge = {last.left, cur.right, calc(last.left, cur.right), calcValue(last.left, cur.right)};
            if (cur.value + last.value > merge.value || cur.x < last.x) {
                cur = merge;
                items.pop_back();
            } else
                break;
        } while (items.size());

        items.push_back(cur);

    }
    double res = 0;
    for (auto &item: items) {
        res += item.value;
    }

    cout << sqrt(res);
    return 0;
}
