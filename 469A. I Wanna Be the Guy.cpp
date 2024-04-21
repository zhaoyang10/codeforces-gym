#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LEN 100010



int main() {
    int n,p,q,t,i;
    bool mark[LEN];
    scanf("%d", &n);
    memset(mark, 0, sizeof(bool));
    scanf("%d", &p);
    while(p--) {
        scanf("%d", &t);
        mark[t] = true;
    }
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &t);
        mark[t] = true;
    }
    for(i = 1; i <= n; i ++) {
        if(!mark[i]){
            printf("Oh, my keyboard!");
            return 0;
        }
    }
    printf("I become the guy.");

    return 0;
}
