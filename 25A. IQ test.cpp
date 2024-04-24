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

    int n;
    int s1, s2, last1, last2, tmp;
    int i;
    s1 = 0;
    s2 = 0;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &tmp);
        if(tmp%2) {
            s1 ++;
            last1 = i+1;
        } else {
            s2 ++;
            last2 = i+1;
        }
    }
    if(s1 == 1) printf("%d", last1);
    else printf("%d", last2);
    return 0;
}
