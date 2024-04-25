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


char str1[LEN], str2[LEN], str3[LEN], str4[LEN];

int main() {
    int len1, len2, len3, len4;
    int i;
    scanf("%s%s%s", str1, str2, str3);
    len1 = strlen(str1);
    len2 = strlen(str2);
    len3 = strlen(str3);
    if(len1+len2 != len3) {
        printf("NO");
        return 0;
    }
    for(i=0; i<len1; i++) {
        str4[i] = str1[i];
    }
    for(i=0; i<len2; i++) {
        str4[i+len1] = str2[i];
    }
    sort(str4, str4 + len1 + len2);
    sort(str3, str3 + len3);
    for(i=0; i<len3; i++) {
        if(str3[i] != str4[i]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
