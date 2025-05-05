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

int s[LEN], t[LEN];
int reverse_tag[LEN];

struct{
    int father;
    int tag;
    vector<int> children;
}node[2*LEN];

int find_root(int leaf) {
    return node[leaf].father==-1 ? leaf : node[leaf].father = find_root(node[leaf].father);
}

void insert(int child, int father){
    node[child].father = father;
    node[father].children.push_back(child);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, q, i, total_num;
    scanf("%d%d", &n,&q);
    for (i=0; i<q; i++)
        scanf("%d%d",&s[i],&t[i]);
    
    total_num = n;
    for (i=1; i<=n; i++){
        node[i].father = -1;
        node[i].tag = i;
        reverse_tag[i] = i;
    }

    for (i=0; i<q; i++) {
        s[i] = reverse_tag[s[i]];
        t[i] = reverse_tag[t[i]];
        if(node[s[i]].father == -1 && node[t[i]].father == -1){
            insert(s[i], t[i]);
        }else if(node[t[i]].father != -1){
            total_num++;
            node[total_num].father = -1;
            node[total_num].tag = node[t[i]].tag;
            reverse_tag[node[total_num].tag] = total_num;
            // insert(t[i], total_num);
            insert(s[i], total_num);
        }
    }

    for (i=1; i<=n; i++) find_root(i);

    for (i=1; i<=n; i++) printf("%d%c", node[i].father==-1? node[i].tag : node[node[i].father].tag, " \n"[i==n]);

    return 0;
}
