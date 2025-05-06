#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <bitset>
#include <utility>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {return b ? gcd(b, a%b): a;}
int gcd(int a, int b) {return b ? gcd(b, a%b): a;}



#define LEN 1000010

int par[LEN], ranks[LEN], col[LEN];

int asc(int u) {return u==par[u]? u:par[u]=asc(par[u]);}
void join(int u, int v){
    if(ranks[u] > ranks[v]) swap(u,v);
    par[u] = v;
    ranks[v] += ranks[u];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, m, i, a, b, fa, fb;

    memset(col, 0, size(col));
    scanf("%d%d", &n,&m);
    for (i=1; i<=n; i++){
        ranks[i] = 1;
        par[i] = i;
    }
    for (i=0; i<m; i++){
        scanf("%d%d", &a, &b);
        fa = asc(a);
        fb = asc(b);
        if(fa!=fb) join(fa, fb);
    }
    for (i=1; i<=n; i++) col[asc(i)] = 1;
    ll ans = 1;
    for (i=1; i<=n; i++){
        if(col[i]){
            // printf("ranks[%d]=%d\n", i, ranks[i]);
            ans *= 1LL << (ranks[i]-1);
        }
    }

    printf("%lld\n", ans);
    return 0;
}
