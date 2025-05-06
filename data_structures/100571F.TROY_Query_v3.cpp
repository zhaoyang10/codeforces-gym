#include <bits/stdc++.h>
using namespace std;

struct DSU {
    unordered_map<long long, long long> parent;
    unordered_map<long long, int> rank;
    unordered_map<long long, int> weight; // XOR from node to parent

    pair<long long, int> find(long long u) {
        if (parent.find(u) == parent.end()) {
            parent[u] = u;
            weight[u] = 0;
            return {u, 0};
        }
        if (parent[u] != u) {
            auto [root, w] = find(parent[u]);
            parent[u] = root;
            weight[u] ^= w;
        }
        return {parent[u], weight[u]};
    }

    bool unite(long long u, long long v, int s) {
        auto [ru, wu] = find(u);
        auto [rv, wv] = find(v);

        if (ru == rv) {
            return (wu ^ wv) == s;
        }

        if (rank[ru] < rank[rv]) {
            swap(ru, rv);
            swap(u, v);
            swap(wu, wv);
        }

        parent[rv] = ru;
        weight[rv] = wu ^ wv ^ s;
        rank[ru] += rank[rv];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    DSU dsu;

    while (n--) {
        long long x, y;
        string a, b;
        cin >> x >> y >> a >> b;
        int a_val = (a[0] == '+') ? 1 : -1;
        int b_val = (b[0] == '+') ? 1 : -1;
        int s = (a_val != b_val) ? 1 : 0;

        long long u = x;
        long long v = -y;

        if (!dsu.unite(u, v, s)) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

    return 0;
}