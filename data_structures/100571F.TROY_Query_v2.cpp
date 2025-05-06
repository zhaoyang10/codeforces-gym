#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAX = 2e5 + 5;

struct DSU {
    unordered_map<ll, pair<ll, int>> parent; // node -> {parent, parity}

    ll find(ll x, int &parity) {
        if (parent.find(x) == parent.end() || parent[x].first == x) {
            parent[x] = {x, 0};
            return x;
        }

        ll px = parent[x].first;
        int cur_parity = parent[x].second;
        ll root = find(px, cur_parity);
        parity ^= cur_parity;
        parent[x] = {root, parity};
        return root;
    }

    bool unite(ll x, ll y, int expected_parity) {
        int px, py;
        ll rx = find(x, px);
        ll ry = find(y, py);

        if (rx == ry) {
            return ((px ^ py) == expected_parity);
        }

        // Merge smaller tree into larger
        parent[ry] = {rx, (px ^ py ^ expected_parity)};
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    
    int n;
    cin >> n;

    DSU row_dsu, col_dsu;

    for (int i = 0; i < n; ++i) {
        ll x, y;
        string a_str, b_str;
        cin >> x >> y >> a_str >> b_str;

        int a = (a_str == "+1") ? 1 : -1;
        int b = (b_str == "+1") ? 1 : -1;

        int diff = (a * b == 1) ? 0 : 1;

        // Constraint: row[x] + col[y] ≡ diff mod 2
        bool ok = row_dsu.unite(x, y + 1e18, diff); // offset y to avoid collision with row indices

        cout << (ok ? "Yes" : "No") << '\n';
    }

    return 0;
}