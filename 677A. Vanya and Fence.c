#include <stdio.h>
#include <stdbool.h>

#define LEN 100000+10

int main(){

    int n, h;
    int a[LEN];
    int sum, i;
    scanf("%d%d", &n, &h);
    for (i = 0; i < n; i ++) scanf("%d", a+i);
    sum = 0;
    for (i = 0; i < n; i ++) {
        if(a[i] > h) sum += 2;
        else sum += 1;
    }
    printf("%d", sum);
    return 0;
}
