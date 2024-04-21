#include <stdio.h>
#include <stdbool.h>
#define LEN 100010



int main() {
    long long n, k, half;
    scanf("%I64d%I64d", &n, &k);
    half = n / 2 + n % 2;
    if (k > half) {
        k -= half;
        printf("%I64d", 2*k);
    } else {
        printf("%I64d", 2*k-1);
    }
    return 0;
}
