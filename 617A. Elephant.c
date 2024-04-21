#include <stdio.h>
#define eps 1e-8


int main()
{
    int a;
    int res = 0;
    scanf("%d", &a);
    res = a / 5 + (a%5 != 0);
    printf("%d", res);
    return 0;
}
