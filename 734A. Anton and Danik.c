#include <stdio.h>
#include <stdbool.h>

#define LEN 100000+10

int main(){

    int n;
    int i, s;
    char str[LEN];
    scanf("%d", &n);
    scanf("%s", str);
    s = 0;
    for (i = 0; i < n; i++) {
        if(str[i] == 'A') s++;
    }
    if (s * 2 == n) printf("Friendship");
    else if (s * 2 > n) printf("Anton");
    else printf("Danik");

    return 0;
}
