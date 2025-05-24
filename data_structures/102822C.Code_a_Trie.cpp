#include<bits/stdc++.h>
using namespace std;
constexpr int MAX_N=300005;

#define ll long long

set<int>val[MAX_N];
int node[MAX_N][26];
int tot;

void insert(string str, int v){
    int i, j, now;
    val[0].insert(v);
    for (i=0, now=0; i<str.length(); i++){
        j = str[i]-'a';
        if(node[now][j] == 0){
            node[now][j] = ++tot;
        }
        now = node[now][j];
        val[now].insert(v);
    }
}

int dfs(int now){
    int res=0, tmp;
    int i, j;
    for (i=0; i<26; i++){
        j = node[now][i];
        if(!j) tmp=dfs(j);
        else continue;
        if(tmp==-1) return -1;
        
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, q, i, v;
    string str;
    cin >>n;
    for (i=1; i<=n; i++){
        tot = 0;    
        cin>>q;
        while(q--){
            cin>>str>>v;
            insert(str, v);
        }
        cout<<"Case #"<<i<<": "<<dfs(0)<<endl;
    }

    return 0;
}
