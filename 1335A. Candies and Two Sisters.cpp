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

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if(n<3) printf("0\n");
        else if(n%2) printf("%d\n", n/2);
        else printf("%d\n", n/2-1);
    }
    return 0;
}
