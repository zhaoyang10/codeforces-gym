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

    int a[LEN];
    int n, head, tail,res;
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i ++) scanf("%d", a+i);
    res = 1;
    head = tail = 0;
    while(tail < n) {
        if (tail == n - 1) {
            tail ++;
            res = max(res, tail - head);
            continue;
        } else if (tail == n - 1 || a[tail+1] >= a[tail]) {
            tail ++;
            res = max(res, tail - head + 1);
            continue;
        }
        tail = tail+1;
        head = tail;
    }

    printf("%d", res);

    return 0;
}
