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
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    for (i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(i%2==1) printf("#");
            else if(i/2%2==1 && j==m || i/2%2==0 && j==1) printf("#");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}
