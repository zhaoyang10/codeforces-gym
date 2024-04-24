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



#define LEN 100010

int main() {
    char cleft, cright, ccomma, cblank, ctemp;
    set<char> setc;
    bool flag = true;
    cright = '}';
    ccomma = ',';
    cblank = ' ';
    scanf("%c", &cleft);
    while(flag) {
        scanf("%c", &ctemp);


        if(ctemp == cright) {
            flag = false;
            continue;
        }
        if(ctemp == ccomma || ctemp == cblank)
            continue;
        setc.insert(ctemp);
    }
    printf("%d", setc.size());
    return 0;
}
