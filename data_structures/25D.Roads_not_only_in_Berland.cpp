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

int s[LEN], t[LEN], par[LEN], as[LEN], at[LEN], ranks[LEN];
set<int> id_set;
vector<int> id_vec;

int asc(int u) {return u==par[u]? u : par[u]=asc(par[u]);}
void join(int u, int v)
{
    if(ranks[u] > ranks[v])     swap(u, v);
    par[u] = v;
    ranks[v] += ranks[u];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, i, num_ans, ia, ib, fa, fb;
    scanf("%d", &n);
    for (i=1; i<=n; i++){
        par[i] = i;
        ranks[i] = 1;
    }
    num_ans=0;
    for (i=1; i<n; i++){
        scanf("%d%d", &ia, &ib);
        fa = asc(ia);
        fb = asc(ib);
        if(fa == fb){
            s[num_ans] = ia;
            t[num_ans] = ib;
            num_ans ++;
        }else{
            join(fa, fb);
        }
    }
    for (i=1; i<=n; i++)  id_set.insert(asc(i));
    for(set<int>::iterator it= id_set.begin(); it != id_set.end(); it++){
        id_vec.push_back(*it);
    }
    for (i=1; i<=num_ans; i++){
        as[i-1] = id_vec[i-1];
        at[i-1] = id_vec[i];
    }

    printf("%d\n", num_ans);
    for (i=0; i<num_ans; i++){
        printf("%d %d %d %d\n", s[i], t[i], as[i], at[i]);
    }
    return 0;
}
