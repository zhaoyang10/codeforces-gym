#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LEN 100010



int main() {
    int n,i;
    int hmax, hmin, hmax_index, hmin_index;
    int h[LEN];
    scanf("%d", &n);
    for (i = 0; i < n; i ++) scanf("%d", h + i);
    hmax = -1;
    hmin = 110;
    for (i = 0; i < n; i ++) {
        if (h[i] > hmax) {
            hmax = h[i];
            hmax_index = i;
        }
        if (h[i] <= hmin) {
            hmin = h[i];
            hmin_index = i;
        }
    }
    if (hmax_index < hmin_index) {
        printf("%d", hmax_index + n - 1 - hmin_index);
    } else {
        printf("%d", hmax_index + n - 1 - hmin_index - 1);
    }

    return 0;
}
