#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LEN 100010



int main() {
    int a,b,c;
    int res, t;
    scanf("%d%d%d", &a, &b, &c);
    res = a + b * c;
    t = a * b + c;
    if (t > res) res = t;
    t = (a + b) * c;
    if (t > res) res = t;
    t = a * (b + c);
    if (t > res) res = t;
    t = a * b * c;
    if (t > res) res = t;
    t = a + b + c;
    if (t > res) res = t;


    printf("%d", res);


    return 0;
}
