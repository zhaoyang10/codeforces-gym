#include <stdio.h>
#define eps 1e-8


int main()
{
    double a,b,c;
    int res = 0;
    scanf("%lf %lf", &a, &b);
    c = a / b;
    while (c < 1 + eps) {
        c *= 1.5;
        res += 1;
        //printf("%lf\n", c);
    }
    printf("%d", res);
    return 0;
}
