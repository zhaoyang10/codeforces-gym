#include <stdio.h>
#include <stdbool.h>


int main(){

    long long n;
    int t, k;
    bool flag;
    scanf("%I64d", &n);
    k = 0;
    while (n) {
        t = n % 10;
        if (t == 4 || t == 7) k ++;
        n = n / 10;
    }

    if (k == 0) {
        printf("NO");
        return 0;
    }

    flag = true;
    while(k) {
        if (k % 10 != 4 && k % 10 != 7) flag = false;
        k = k / 10;
    }

    if(flag) printf("YES");
    else     printf("NO");

    return 0;
}
