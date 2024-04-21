#include <stdio.h>



int main(){

    int n;
    int sum_x, sum_y, sum_z;
    int x,y,z;
    scanf("%d", &n);
    sum_x = 0;
    sum_y = 0;
    sum_z = 0;
    while(n--){
        scanf("%d%d%d", &x, &y, &z);
        sum_x += x;
        sum_y += y;
        sum_z += z;
    }
    if(sum_x == 0 && sum_y == 0 && sum_z ==0) printf("YES");
    else printf("NO");

    return 0;
}
