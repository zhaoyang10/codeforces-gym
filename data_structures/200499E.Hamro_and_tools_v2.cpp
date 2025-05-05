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

int box[LEN], par[LEN], s[LEN], t[LEN], inbox[LEN];

int asc(int x){
    return x == par[x] ? x : par[x] = asc(par[x]);
}
void join_box(int u, int v){
    par[asc(u)] = asc(v);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, q, i;
    scanf("%d%d", &n,&q);
    for (i=0; i<q; i++)
        scanf("%d%d",&s[i],&t[i]);
    
    for (i=1; i<=n; i++){
        box[i] = i;
        par[i] = i;
    }

    for (i=0; i<q; i++) {
        if(!box[s[i]]) continue;
        if(!box[t[i]]){
            box[t[i]] = box[s[i]];
        } else {
            join_box(box[s[i]],box[t[i]]);
        }
        box[s[i]] = 0;
    }

    for (i=1; i<=n; i++) if(box[i]) inbox[box[i]]=i;

    for (i=1; i<=n; i++) printf("%d%c", inbox[asc(i)], " \n"[i==n]);

    return 0;
}
