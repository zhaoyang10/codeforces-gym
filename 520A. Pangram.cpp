#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LEN 100010



int main() {
    int n,i;
    bool mark[LEN];
    char str_in[LEN];
    scanf("%d%s", &n, str_in);
    memset(mark, false, sizeof(bool));
    for (i = 0; i < n; i ++) {
        if (str_in[i] - 'A' >= 0 && str_in[i] - 'Z'<= 0) mark[str_in[i] - 'A'] = true;
        else mark[str_in[i] - 'a'] = true;
    }
    for (i = 0; i <= 'z' - 'a'; i ++) {
        if (!mark[i]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");

    return 0;
}
