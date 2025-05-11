#include<bits/stdc++.h>
using namespace std;
constexpr int MAX_N=200005;

#define ll long long

struct trie{
    int cnt, node[MAX_N][26];
    bool word[MAX_N];
    int dp[MAX_N];

    void init(){
        memset(node, 0, sizeof(node));
        memset(word, 0, sizeof(word));
        memset(dp, 0, sizeof(dp));
        cnt = 1;
    }

    void insert(string str){
        int ptr = 0;
        for (int i=0; i<str.length(); i++){
            if(node[ptr][str[i]-'a'] == 0) {
                node[ptr][str[i]-'a'] = cnt;
                ptr = cnt; 
                cnt++;
            }else{
                ptr = node[ptr][str[i]-'a'];
            }
        }
        word[ptr] = true;
        // cout<<"cnt="<<cnt<<endl;
    }

    void dfs(int nd){
        int wchild = 0;
        int i;
        for (i=0; i<26; i++) wchild |= node[nd][i];
        if (wchild == 0){
            dp[nd] = 1;
            return;
        }
        
        int flag[4] = {0, 0, 0, 0};
        for (i=0; i<26; i++){
            if(node[nd][i] == 0) continue;
            dfs(node[nd][i]);
            flag[dp[node[nd][i]]] = 1;
        }
        if(flag[3]) dp[nd] = 0;
        else if(flag[1] && flag[2]) dp[nd] = 0;
        else if(flag[1]) dp[nd] = 2;
        else if(flag[2]) dp[nd] = 1;
        else if(flag[0]) dp[nd] = 3;
    }
} root;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, q;
    string str;
    cin >> n >> q;
    root.init();
    while(n--){
        cin >> str;
        root.insert(str);
    }
    root.dfs(0);
    
    if(root.dp[0] == 2) {
        if(q&1) cout<<"First";
        else cout<<"Second";
    }else if(root.dp[0] == 1) {
        cout<<"Second";
    }else if (root.dp[0] == 0){
        cout<<"First";
    }else{
        cout<<"Second";
    }
    cout<<endl;
    return 0;
}
