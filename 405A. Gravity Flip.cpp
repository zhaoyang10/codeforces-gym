#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LEN 100010



int main() {
    int i, n;
    int a[LEN];
    scanf("%d", &n);
    for (i = 0; i < n; i ++) {
        scanf("%d", a + i);
    }
    sort(a, a+i);
    for (i = 0; i < n; i ++) {
        printf("%d ", a[i]);
    }

    return 0;
}
