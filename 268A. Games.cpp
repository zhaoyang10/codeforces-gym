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

int c[LEN][2];

int main() {

    int n, i, j, s;
    s = 0;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d%d", &c[i][0], &c[i][1]);
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i == j) continue;
            if(c[i][0] == c[j][1]) s++;
        }
    }
    printf("%d", s);
    return 0;
}
