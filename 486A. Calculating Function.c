#include <stdio.h>
#include <stdbool.h>
#define LEN 100010



int main() {
    int n, m, i;
    int p[LEN], res[LEN];
    scanf("%d", &n);
    for (i = 1; i <= n; i ++) {
        scanf("%d", p + i);
        res[p[i]] = i;
    }
    for (i = 1; i < n; i ++) {
        printf("%d ", res[i]);
    }
    printf("%d", res[n]);

    return 0;
}
