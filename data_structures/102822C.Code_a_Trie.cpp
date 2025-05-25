#include <bits/stdc++.h>
 
#define SZ(x) (int)x.size()
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXLOG = 22;
namespace Discrete {
    int b[MAXN], btol, blen;
 
    void insert(int x) { b[btol++] = x; }
 
    void init() {
        sort(b, b + btol);
        blen = unique(b, b + btol) - b;
    }
 
    int val2id(int x) {
        return lower_bound(b, b + blen, x) - b + 1;
    }
}
using Discrete::val2id;
 
 
class TRIE {
public:
    int T[MAXN][26], top;
 
    void init() {
        top = 1;
        memset(T[top], 0, sizeof(T[top]));
    }
 
    int insert(const string &s, int n) {
        int u = 1;
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            if (!T[u][ch]) {
                T[u][ch] = ++top;
                memset(T[top], 0, sizeof(T[top]));
            }
            u = T[u][ch];
        }
        return u;
    }
 
    int dep[MAXN], fa[MAXN][MAXLOG], lg[MAXN];
 
    void init(int _n) {
        for (int i = 1; i <= _n; i++) {
            lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
        }
    }
 
 
    inline void dfs(int u, int f) {
        fa[u][0] = f, dep[u] = dep[f] + 1;
        for (int i = 1; i <= lg[dep[u]]; i++) fa[u][i] = fa[fa[u][i - 1]][i-1];
        for (int i = 0; i < 26; i++) {
            int v = T[u][i];
            if (v == f) continue;
            if (v) dfs(v, u);
        }
    }
 
    void get_lca() {
        for (int i = 1; i <= top; i++) memset(fa[i], 0, sizeof(fa[i]));
        dep[1] = 0;
        dfs(1, 1);
    }
 
    int LCA(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        while (dep[u] > dep[v]) u = fa[u][lg[dep[u] - dep[v]] - 1];
        if (u == v) return u;
        for (int k = lg[dep[u]] - 1; k >= 0; k--) {
            if (fa[u][k] != fa[v][k]) u = fa[u][k], v = fa[v][k];
        }
        return fa[u][0];
    }
 
    int lca_val[MAXN], die[MAXN];
 
    void find_lca_init() {
        for (int i = 1; i <= top; i++) lca_val[i] = 0;
        for (int i = 1; i <= top; i++) die[i] = 0;
    }
 
    int dfs_die(int u, int die_flag) {
        if (die[u]) die_flag = 1;
        if (lca_val[u] && die_flag) return 0;
        for (int i = 0; i < 26; i++) {
            int v = T[u][i];
            if (v) {
                if (!dfs_die(v, die_flag)) return 0;
            }
        }
        return 1;
    }
 
    int lca_cnt[MAXN], vis[MAXN];
 
    inline void dfs_ans(int u) {
        int fg = 0;
        for (int i = 0; i < 26; i++) {
            int v = T[u][i];
            if (v) {
                dfs_ans(v);
                lca_cnt[u] += lca_cnt[v];
                if (lca_cnt[v] == 1) {
                    fg = v; //break;
                }
            }
        }
        if (lca_val[u]) lca_cnt[u]++;
        if (!lca_val[u] && fg) {
            vis[u] = 1, vis[fg] = 0;
        } else if (lca_cnt[u]) vis[u] = 1;
 
    }
 
    int solve() {
        for (int i = 1; i <= top; i++) lca_cnt[i] = vis[i] = 0;
        dfs_ans(1);
        int ans = 0;
        for (int i = 1; i <= top; i++) ans += vis[i];//, printf("%d\n", lca_cnt[i]);
        return ans;
    }
 
} tree;
 
 
string str[MAXN];
int val[MAXN], endpos[MAXN];
vector<int> vec[MAXN];
 
int main() {
    tree.init(MAXN - 1); // init for lg
    int T;
    cin >> T;
    int kass = 1;
    while (T--) {
        Discrete::btol = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> str[i] >> val[i];
            Discrete::insert(val[i]);
        }
        Discrete::init();
        for (int i = 1; i <= n; i++) val[i] = val2id(val[i]);
 
        unordered_map<int, int> ma; // same string two val
        int res = 1;
 
        tree.init();
        for (int i = 1; i <= n; i++) {
            endpos[i] = tree.insert(str[i], SZ(str[i]));
            if (ma.find(endpos[i]) != ma.end()) {
                if (ma[endpos[i]] != val[i]) {
                    res = 0;
                    break;
                }
            }
            ma[endpos[i]] = val[i];
        }
 
        if (!res) { // no result
            printf("Case #%d: -1\n", kass++);
            continue;
        }
 
        tree.get_lca();
 
        for (int i = 1; i <= Discrete::blen; i++) vec[i].clear();
        for (int i = 1; i <= n; i++) {
            vec[val[i]].push_back(i);
        }
 
 
        tree.find_lca_init();
        for (int i = 1; i <= Discrete::blen; i++) {
            int lca = endpos[vec[i][0]];
            for (int j = 1; j < SZ(vec[i]); j++) lca = tree.LCA(lca, endpos[vec[i][j]]);
            if (tree.lca_val[lca]) {
                res = 0;    // two value have same lca
                break;
            } else {
                tree.lca_val[lca] = i;
                int k = tree.dep[lca];
                for (auto e: vec[i]) {
                    if (SZ(str[e]) >= k) {
                        //   printf("%d\n", tree.T[lca][str[e][k - 1]-'a']);
                        tree.die[tree.T[lca][str[e][k - 1]-'a']] = 1;
                    }
                }
            }
        }
 
        if (!res) { // no result
            printf("Case #%d: -1\n", kass++);
            continue;
        }
 
        if (!tree.dfs_die(1, 0)) {
            printf("Case #%d: -1\n", kass++);
            continue;
        }
 
        printf("Case #%d: %d\n", kass++, tree.solve());
 
    }
}
 
/*
4
s 748384849
aeqa 748384849
succk 40574105
a 332084817
 */