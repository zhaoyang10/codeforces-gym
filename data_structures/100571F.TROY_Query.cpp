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



#define LEN 1000100

int parent[LEN*2], rank_set[LEN*2], parity[LEN*2];
map<string, int> index_map;

int asc(int u){
   if(parent[u] == u) {
        parity[u] = 0;
        return u;
   } 
   int pu;
   pu = parent[u];
   parent[u] = asc(parent[u]);
   parity[u] = parity[u]^parity[pu];
   return parent[u];
}

void join(int u, int v, int parity_uv){
    if(rank_set[u] < rank_set[v]){
        parent[u] = v;
        parity[u] = parity_uv;
        rank_set[v] += rank_set[v];
    } else{
        parent[v] = u;
        parity[v] = parity_uv;
        rank_set[u] += rank_set[v];
    }
    // printf("u=%d\tv=%d\tparity_uv=%d\n", u,v, parity_uv);
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, i, a, b;
    string x, y, a_str, b_str;
    int num_x, num_y, parity_xy;
    cin>>n;
    for (i=0; i<2*LEN; i++) {
        parent[i] = i;
        rank_set[i] = 1;
    }
    // memset(rank_set, 0, sizeof(rank_set));
    memset(parity, 0, sizeof(parity));
    while(n--) {
        cin>>x>>y>>a_str>>b_str;
        x = 'c'+x;
        y = 'r'+y;
        // cout<<x<<y<<a<<b<<endl;
        if(index_map.find(x) == index_map.end()) index_map[x] = index_map.size();
        if(index_map.find(y) == index_map.end()) index_map[y] = index_map.size();
        
        a = (a_str == "+1") ? 1 : -1;
        b = (b_str == "+1") ? 1 : -1;
        parity_xy = (a * b == 1) ? 0 : 1;

        num_x = asc(index_map[x]);
        num_y = asc(index_map[y]);
        
        // printf("x=%d\ty=%d\tnum_x=%d\tnum_y=%d\n",index_map[x], index_map[y], num_x,num_y);
        // printf("parity[%d]=%d\tparity[%d]=%d\tparity_xy=%d\n", index_map[x], parity[index_map[x]], index_map[y], parity[index_map[y]], parity_xy);
        if(num_x == num_y) {
            if((parity[index_map[x]] ^ parity[index_map[y]]) != parity_xy){
                printf("No\n");
            }else{
                printf("Yes\n");
            }
        } else{
            printf("Yes\n");
            join(num_x, num_y, parity[index_map[x]] ^ parity[index_map[y]] ^ parity_xy);
        }
    }

    return 0;
}
