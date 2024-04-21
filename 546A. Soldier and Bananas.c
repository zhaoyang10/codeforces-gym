#include <stdio.h>
#define eps 1e-8


int main()
{
    int k,w,n;
    int sum, res = 0;
    scanf("%d %d %d", &k, &n, &w);
    sum = w * (1 + w) / 2 * k;
    res = sum - n;
    res = res > 0 ? res: 0;
    printf("%d", res);
    return 0;
}
