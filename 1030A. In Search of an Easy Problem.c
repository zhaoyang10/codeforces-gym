#include <stdio.h>
#include <stdbool.h>
#define LEN 100010



int main() {
    int n, i, m, s;
    scanf("%d", &n);
    s = 0;
    for (i = 0; i < n; i ++) {
        scanf("%d", &m);
        s += m;
    }
    if (s == 0) printf("EASY");
    else printf("HARD");
    return 0;
}
