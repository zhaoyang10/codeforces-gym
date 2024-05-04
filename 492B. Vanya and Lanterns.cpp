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
    int n, l, tmp;
    int i; 
    double ans;
    scanf("%d%d", &n, &l);
    for(i=0; i<n; i++) scanf("%d", a+i);
    sort(a, a+n);
    ans = a[0];
    ans = max(ans, double(l-a[n-1]));
    for(i=1; i<n; i++) {
        ans = max((a[i]-a[i-1])/2.0, ans);
    }
    printf("%lf", ans);
    return 0;
}
