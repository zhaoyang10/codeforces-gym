#include <stdio.h>
#include <stdbool.h>
#define LEN 100010



int main() {
    int n, i, m, s, p;
    scanf("%d", &n);
    s = 0;
    p = 0;
    for (i = 0; i < n; i ++) {
        scanf("%d", &m);
        if (p != m) s += 1;
        p = m;
    }
    printf("%d", s);

    return 0;
}
