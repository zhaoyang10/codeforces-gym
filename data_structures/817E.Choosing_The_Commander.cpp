    #include<bits/stdc++.h>
    using namespace std;
    constexpr int MAX_N=2000005;
     
    #define ll long long
     
    int num_n;
    int node[MAX_N][2];
    int sum[MAX_N];
    int ans;
     
    void insert(int num, int weight){
        int i, j, now=1;
        for (i=30; i>=0; i--){
            j = (num>>i)&1;
            if(node[now][j] == -1) {
                num_n++;
                node[now][j] = num_n;
                now = num_n;
            }else{
                now = node[now][j];
            }
            sum[now] += weight;
        }
    }
     
    void query(int u, int v)
    {
        int i, j, k, now=1;
        for (i=30; i>=0; i--){
            j = (u>>i)&1;
            k = (v>>i)&1;
            if(j == 0 && k == 0){
                now = node[now][0];
            }else if(j == 1 && k == 0){
                now = node[now][1];
            }else if(j == 0 && k == 1){
                if(node[now][0]!=-1) ans += sum[node[now][0]];
                now = node[now][1];
            }else if(j == 1 && k == 1){
                if(node[now][1]!=-1) ans += sum[node[now][1]];
                now = node[now][0];
            }
            if(now == -1) break;
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
        int n, op, i, j;
        cin>>n;
        num_n = 1;
        
        memset(node, -1, sizeof(node));
        memset(sum, 0, sizeof(sum));
     
        while(n--)
        {
            cin>>op;
            if (op == 1) {
                cin>>i;
                insert(i, 1);
            } else if(op == 2) {
                cin>>i;
                insert(i, -1);
            } else {
                cin>>i>>j;
                ans = 0;
                query(i, j);
                cout << ans <<endl;
            }
        }
        return 0;
    }