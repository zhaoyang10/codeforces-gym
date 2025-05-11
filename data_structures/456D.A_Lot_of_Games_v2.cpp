//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
#define usint unsigned int
#define mz(array) memset(array, 0, sizeof(array))
#define minf(array) memset(array, 0x3f, sizeof(array))
#define REP(i,n) for(i=0;i<(n);i++)
#define FOR(i,x,n) for(i=(x);i<=(n);i++)
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define WN(x) printf("%d\n",x);
#define RE  freopen("D.in","r",stdin)
#define WE  freopen("1biao.out","w",stdout)

const int maxn=111111;
int n,k;
char s[maxn];
int chd[maxn][26];
int canwin[maxn],canlose[maxn];
int tn;
int ID[128];

void insert(char *s) {
    int len=strlen(s),i;
    int now=0;
    for(i=0; i<len; i++) {
        if(!chd[now][ID[s[i]]]) chd[now][ID[s[i]]]=tn , now=tn++;
        else now=chd[now][ID[s[i]]];
    }
    // printf("tn = %d\n",tn);
}

void dfs(int x) {
    int i;
    bool last=true;
    bool cwin=0,close=0,canwinlose=0,cant=0;
    for(i=0; i<26; i++) {
        if(chd[x][i]!=0) {
            //printf("%c:",'a'+i);
            dfs(chd[x][i]);
            last=false;
            if(canwin[chd[x][i]]){///统计儿子有4种点中的哪些点
                if(canlose[chd[x][i]])canwinlose=1;
                else cwin=1;
            }
            else {
                if(canlose[chd[x][i]]) close=1;
                else cant=1;
            }
        }
    }
    canwin[x]=0;canlose[x]=0;///初始化为0,0
    if(last)canwin[x]=1;
    else{
        if(canwinlose==0){///如果儿子里有有能赢又能输的点，当前点肯定是0,0，没有这种点才继续看
            if(!(cwin && close)){///如果儿子里又有赢点又有输点，当前点肯定是0,0，不是这种情况才继续看
                if(cant && !cwin && !close)///如果儿子只有0,0点，当前点肯定是1,1点
                    canwin[x]=1,canlose[x]=1;
                else if(cwin)///如果儿子只有赢点，当前点肯定是输点
                    canlose[x]=1;
                else if(close)///儿子只有输点，当前点肯定是赢点
                    canwin[x]=1;
            }
        }
    }
    // printf("%d=(%d,%d)\n",x, canwin[x],canlose[x]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int i,j;
    REP(i,26) {
        ID[i+'a']=i;
    }
    while(scanf("%d%d",&n,&k)!=EOF) {
        mz(chd);
        tn=1;
        for(i=0; i<n; i++) {
            scanf("%s",s);
            insert(s);
        }
        canwin[0]=0;canlose[0]=0;
        for(i=0; i<26; i++) {///众起点中有赢点，走这个点就必赢；有输点，走这个点就必输。
            if(chd[0][i]!=0) {
                dfs(chd[0][i]);
                if(canwin[chd[0][i]])canwin[0]=1;
                if(canlose[chd[0][i]])canlose[0]=1;
                // printf("%c,%d,%d\n",'a'+i,canwin[chd[0][i]],canlose[chd[0][i]]);
            }
        }
        //printf("%d,%d\n",canwin[0],canlose[0]);
        bool first=false;
        if(canwin[0])
            if(canlose[0]) first=true;///能输能赢，乃真正法器（连输，最后赢一局）
            else if((k&1)==1)first=true;///能赢不能输，则必轮流赢
        ///其他情况不能必赢
        if(first)puts("First");
        else puts("Second");
    }
    return 0;
}