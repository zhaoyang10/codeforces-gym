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
#define MOD 1000000007LL

ll gcd(ll a, ll b) {return b ? gcd(b, a%b): a;}
int gcd(int a, int b) {return b ? gcd(b, a%b): a;}



#define LEN 1000010
int f[LEN], s[LEN], x[LEN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, q, a, b, i, l, r;
    
    scanf("%d%d",&n,&q);
    scanf("%d%d%d%d",&f[1],&f[2],&a,&b);
    memset(s, 0, sizeof(s));
    for (i=1; i<=n; i++) scanf("%d",&x[i]);
    for (i=3; i<=n; i++) f[i] = (a*1LL*f[i-2] + b*1LL*f[i-1])%MOD;
    f[0] = 0;


    while(q--){
        scanf("%d%d",&l,&r);
        if(l == r){
            x[l] = (x[l] + f[1] + MOD) % MOD;

            continue;
        }
        s[l] = (s[l] + f[1]) % MOD;
        s[l+1] = (s[l+1] - f[1]*1LL*b%MOD + f[2] + MOD) % MOD;
        s[r+1] = (s[r+1]*1LL - f[r-l+2] + MOD) % MOD;
        s[r+2] = (s[r+2]*1LL - a*1LL*f[r-l+1]%MOD + MOD) % MOD;
    }
    for (i=2; i<=n; i++) s[i] = ((a*1LL*s[i-2]%MOD + b*1LL*s[i-1]%MOD) % MOD + s[i]) % MOD;
    for (i=1; i<=n; i++) x[i] = (x[i]*1LL + s[i]) % MOD;
    for (i=1; i<=n; i++) printf("%d%c",x[i]," \n"[i==n]);
    return 0;
}
