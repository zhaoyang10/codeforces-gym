#include <stdio.h>
#include <stdbool.h>
#define LEN 100010



int main() {
    int n, i;
    double s;
    int p[LEN];
    scanf("%d", &n);

    s = 0;
    for (i = 0; i < n; i ++) {
        scanf("%d", p + i);
        s += p[i];
    }
    printf("%.5lf", 1.0 * s / n);
    return 0;
}
