#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LEN 100010



int main() {
    int i, n;
    char * str_odd = " that I love";
    char * str_even = " that I hate";
    scanf("%d", &n);
    printf("I hate");
    for(i = 2; i <= n; i ++) {
        if (i % 2 == 0) printf("%s", str_odd);
        else printf("%s", str_even);
    }
    printf(" it");
    return 0;
}
