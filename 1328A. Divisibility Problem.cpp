#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LEN 100010



int main() {
    int t,a,b;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        printf("%d\n", a%b?b-a%b:0);
    }
    return 0;
}
