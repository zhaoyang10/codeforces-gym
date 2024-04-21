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

int a[LEN], mark[LEN];
int res, d;

void dfs(int dep) {
    if (dep == 4) {
        int i, cnt = 0, div = 1;

        for (i = 0; i < 4; i ++) {
            if (mark[i]) {
                cnt ++;
                div = div * a[i] / gcd(div, a[i]);
            }
        }
        if (cnt == 0) return;

        if (cnt % 2) {
            res += d / div;
        } else {
            res -= d / div;
        }
        return;
    }
    mark[dep] = 0;
    dfs(dep + 1);
    mark[dep] = 1;
    dfs(dep + 1);
}

int main() {
    int k, l, m, n;
    scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &d);
    res = 0;
    dfs(0);
    printf("%d", res);

    return 0;
}
