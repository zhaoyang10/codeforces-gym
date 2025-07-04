#include<bits/stdc++.h>
using namespace std;
constexpr int MAX_N=25000005;
constexpr int MAX_L=5010;

#define ll long long

int now, n, tot;
bool dp[MAX_L][MAX_L];
char str[MAX_L], ans[MAX_L];

struct trie{
    int node[MAX_L*MAX_L][2], cnt, n_cnt[MAX_L*MAX_L], start[MAX_L*MAX_L], depth[MAX_L*MAX_L];
    void init(){
        memset(node, 0, sizeof(node));
        memset(n_cnt, 0, sizeof(n_cnt));
        cnt=1;
        tot=0;
    }
    void insert(char* str, int pstart, int pdepth){
        // cout<<str<<","<<pstart<<endl;
        int i, ptr, idx;
        ptr = 0;
        for (i=0; i<pdepth; i++){
            idx = str[i]-'a';
            if(node[ptr][idx] == 0){
                node[ptr][idx] = cnt;
                ptr = cnt;
                cnt ++;
            }else{
                ptr = node[ptr][idx];
            }
            if(dp[pstart][i+1]) n_cnt[ptr]+=1;
        }
        // start[ptr] = pstart;
        // depth[ptr] = pdepth;
    }

    void dfs(int nd){
        // cout<<str.substr(start[nd], depth[nd])<<": now="<<now<<" n_cnt="<<n_cnt[nd]<<" "
        // <<start[nd]<<","<<depth[nd]<<"="<<dp[start[nd]][depth[nd]]<<endl;
        now += n_cnt[nd];
        
        if(now >= n){
            // ans = nd;
            // cout<<str.substr(start[ans], depth[ans])<<endl;
            // for (int i=start[ans]; i<start[ans]+depth[ans]; i++)    printf("%c", str[i]);
            for (int i=0; i<tot; i++) printf("%c", ans[i]);
            printf("\n");
            exit(0);
        }
        int i;
        for (i=0; i<2; i++){
            ans[tot++] = 'a'+i;
            if(node[nd][i]) dfs(node[nd][i]);
            tot--;
        }
            
        return;
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
    int i, j, len;
    // cin>>str>>n;
    scanf("%s%d", str, &n);
    len = strlen(str);
    root.init();
    memset(dp, 0, sizeof(dp));

    // cout<<"insert-out"<<endl;
    
    for (i=0; i<len; i++)  dp[i][1] = 1;
    if(len>1) for (i=0; i<len-1; i++) dp[i][2] = str[i] == str[i+1];
    if(len>2) for (i=0; i<len-2; i++) dp[i][3] = str[i] == str[i+2];
    if(len>3) for (i=0; i<len-3; i++) dp[i][4] = str[i] == str[i+3];
    // printf("length = %d\n", len);
    for (i=5; i<=len; i++)
        for(j=0; i+j <= len; j++){
            dp[j][i] = dp[j+2][i-4] && (str[j] == str[j+i-1]);
            // printf("dp[%d][%d] = dp[%d][%d] && (str[%d] == str[%d])\n", j, i, j+2, i-4, j, j+i-1);
            // printf("%d\t%d\t%c\t%c\t%d\n", dp[j][i], dp[j+2][i-4], str[j], str[j+i-1], (str[j] == str[j+i-1]));
        }

    for (i=0; i<len; i++)
            // root.insert(str.substr(i,j-i+1), i, j-i+1);
            root.insert(str+i, i, len-i);
    
    // cout<<"dfs-in\n";
    root.dfs(0);
    // cout<<"dfs-out\n";
    // cout<<ans<<endl;
    // cout<<str.substr(root.start[ans], root.depth[ans])<<endl;

    return 0;
}
