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



#define LEN 10

int main() {
    int t, n, len, tmp, i;
    char str_in[LEN];
    int ans[LEN];
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        tmp=1;
        len=0;
        while(n) {
            if(n%10) {
                ans[len] = tmp*(n%10);
                len++;
            }
            tmp*=10;
            n/=10;
        }
        printf("%d\n", len);
        for(i=0; i<len; i++) printf("%d ",ans[i]);
        printf("\n");
    }    
    return 0;
}
