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

int a[LEN], s[LEN];

int main() {
    int n, i, ans;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", a+i);
    }
    s[0] = 0;
    ans = 0;
    for(i=0; i<n; i++){
        s[i+1] = s[i] + a[i]; 
        if(s[i+1] < 0){
            ans -= s[i+1];
            s[i+1] = 0;
        } 
    }
    printf("%d", ans);
    return 0;
}
