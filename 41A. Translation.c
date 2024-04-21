#include <stdio.h>
#include <stdbool.h>

#define LEN 100000+10

int main(){

    char str_s[LEN], str_t[LEN];
    int len_s, len_t;
    int i;
    scanf("%s%s", str_s, str_t);
    len_s = strlen(str_s);
    len_t = strlen(str_t);
    if (len_s != len_t) {
        printf("NO");
        return 0;
    }

    for(i = 0; i < len_s; i++) {
        if (str_s[i] != str_t[len_s - 1 - i]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
