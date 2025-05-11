#include<bits/stdc++.h>
using namespace std;
constexpr int MAX_N=5005;

#define ll long long

int n, cnt, tot;
char str[MAX_N], dp[MAX_N][MAX_N], ans[MAX_N];
int node[MAX_N*MAX_N][2], sum[MAX_N*MAX_N];

void dfs(int nd){
    // printf("n = %d\tsum[%d] = %d\n", n, nd, sum[nd]);
    if(sum[nd]>=n){
        for (int i=0; i<tot; i++) printf("%c", ans[i]);
        exit(0);
    }
    n -= sum[nd];
    for (int i=0; i<2; i++){
        ans[tot++] = 'a'+i;
        if(node[nd][i]) dfs(node[nd][i]);
        tot--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int i, j, idx, len, ptr;

    scanf("%s%d", str, &n);
    len = strlen(str);
    
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

    cnt = 1;
    for (i=0; i<len; i++){
        ptr = 0;
        for(j=i; j<len; j++){
            idx = str[j] - 'a';
            if(node[ptr][idx] == 0){
                node[ptr][idx] = cnt;
                ptr = cnt; 
                cnt++;
            }else{
                ptr = node[ptr][idx];
            }
            if(dp[i][j-i+1]) sum[ptr]++;
        }
    }

    dfs(0);
  

    return 0;
}
