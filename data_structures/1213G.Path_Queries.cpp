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

ll ans, ans_out[LEN];

int u[LEN], v[LEN], w[LEN], par[LEN], ran[LEN], idx[LEN], idxq[LEN], q[LEN];

int asc(int u){return u==par[u]? u : par[u]=asc(par[u]);}
void join(int u, int v){
    if(ran[u] > ran[v])     swap(u,v);
    // printf("in:ans=%lld\n", ans);
    ans -= (1LL*ran[u]*(ran[u]-1))/2;
    ans -= (1LL*ran[v]*(ran[v]-1))/2;
    ans += (1LL*(ran[u]+ran[v])*(ran[u]+ran[v]-1))/2;
    // printf("out: ans=%lld\n", ans);
    par[u] = v;
    ran[v] += ran[u];
}
bool cmp(int a, int b){
    return w[a] < w[b];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, m, i, pl, pr, fu, fv;
    ans = 0;

    scanf("%d%d", &n,&m);
    
    for (i=1; i<n; i++){
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
    }
    for (i=1; i<=n; i++){
        idx[i] = i;
        par[i] = i;
        ran[i] = 1;
    }
    // sort(idx+1, idx+n, [&](int a, int b){return w[a] < w[b];});
    // sort(idx+1, idx+n, cmp);
    sort(idx + 1, idx + n, [&](int a, int b) {
        return w[a] < w[b];
    });
    for (i=0; i<m; i++) scanf("%d", &q[i]);
    for (i=0; i<m; i++) idxq[i]=i;
    sort(idxq, idxq+m, [&](int a, int b){
        return q[a] < q[b];
    });
    pl = 1;
    pr = 0;
    while(pr<m){
        while(pl<n && w[idx[pl]] <= q[idxq[pr]]){
            fu = asc(u[idx[pl]]);
            fv = asc(v[idx[pl]]);
            // printf("u[%d]=%d\tfu=%d\tv[%d]=%d\tfv=%d\n",pl, u[pl], fu, pl, v[pl], fv);
            if(fu == fv) {
                pl ++;
                continue;
            }
            join(fu, fv);
            pl ++;
        }
        ans_out[idxq[pr]] = ans;
        // printf("%lld%c", ans, " \n"[pr==m]);
        pr++;
    }
    for (i=0; i<m; i++) printf("%lld%c", ans_out[i], " \n"[i==m-1]);
    return 0;
}
