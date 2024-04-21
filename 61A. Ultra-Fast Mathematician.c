#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LEN 100010



int main() {
    char str_a[LEN], str_b[LEN], str_res[LEN];
    int len, i;
    scanf("%s%s", str_a, str_b);
    len = strlen(str_a);
    for (i = 0; i < len; i ++) {
        if (str_a[i] == str_b[i]) str_res[i] = '0';
        else str_res[i] = '1';
    }
    str_res[len] = '\0';
    printf("%s", str_res);
    return 0;
}
