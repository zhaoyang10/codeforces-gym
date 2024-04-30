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

int a[LEN];
int main() {
    int n,m,i,max_diff;
    scanf("%d%d", &n, &m);
    for(i=0; i<m; i++) scanf("%d", a+i);
    max_diff=1100;
    sort(a, a+m);
    for(i=n-1; i<m; i++){
        max_diff=min(max_diff, a[i]-a[i-n+1]);
    }
    printf("%d", max_diff);
    return 0;
}
