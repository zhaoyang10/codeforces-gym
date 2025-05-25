#include<bits/stdc++.h>
using namespace std;
constexpr int MAX_N=200005;

#define ll long long

vector<pair<int, string>> vis;
int trie[MAX_N][26];
int val[MAX_N];
int tot, ans;

string lcp(int ibegin, int iend){
    if (ibegin == iend) return vis[ibegin].second;
    int i, j, flag, len=vis[ibegin].second.length();
    for (i = ibegin+1; i<=iend; i++)    len = len>vis[i].second.length()? vis[i].second.length():len;
    for (i=0; i<len; i++){
        if (vis[iend].second[i] != vis[ibegin].second[i]) {
            break;
        }
    }
    // vis[ibegin].second.resize(i);
    return vis[ibegin].second.substr(0, i);
}

void insert(string str, int v){
    // cout<<"insert="<<str<<"\t"<<"v="<<v<<endl;
    int i, j, p = 0;
    for (i=0; i<str.length(); i++){
        j = str[i] - 'a';
        if(!trie[p][j]) {
            trie[p][j] = ++tot;
            p = tot;
        }else{
            p = trie[p][j];
        }
    }
    val[p] = v;
}

bool dfs(int root){
    int i, j, cnt=0, v=0;
    for (i=0; i<26; i++){
        if(trie[root][i]){
            cnt ++;
            if(dfs(trie[root][i])){
                v = val[trie[root][i]];
            }
        }
    }
    if(val[root] == 0 && v != 0){
        ans --;
        val[root] = v;
        if(cnt == 1){
            return true;
        }
    }
    return cnt == 0;
}

int check(string str){
    int i, j, p=0;
    for (i=0; i<str.length(); i++){
        j=str[i]-'a';
        if(trie[p][j]){
            p = trie[p][j];
        } else {
            break;
        }
    }
    // cout<<str<<":"<<val[p]<<endl;
    return val[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, q, i, j, pv, psi;
    string ps;
    int inp_f;
    string inp_s;
    cin>>n;
    tot=0;
    for (i=1; i<=n; i++){
        cin>>q;
        vis.clear();
        for (j=0; j<=tot+1; j++){
            memset(trie[j], 0, sizeof(trie[j]));
            val[j]=0;
        }
        // memset(trie, 0, sizeof(trie));
        // memset(val, 0, sizeof(val));
        tot=0;
        for (j=0; j<q; j++) {
            cin>>inp_s>>inp_f;
            vis.push_back(pair(inp_f, inp_s));
            // cin>>vis[j].second>>vis[j].first;
        }
        sort(vis.begin(), vis.end());
        pv = vis[0].first;
        psi = 0;
        for (j=1; j<q; j++){
            if (vis[j].first != pv){
                ps  = lcp(psi, j-1);
                insert(ps, pv);
                // ps = vis[j].second;
                pv = vis[j].first;
                psi = j;
            }
        }
        ps = lcp(psi, q-1);
        insert(ps, pv);

        ans = tot + 1;
        dfs(0);

        for (j=0; j<q; j++){
            if(check(vis[j].second) != vis[j].first){
                ans = -1;
                break;
            }
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}
