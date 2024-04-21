#include <stdio.h>
#include <stdbool.h>
#define LEN 100010

int years[LEN];
int used[11];
int num_years;

void dfs(int dep, int year) {

    if (dep == 4) {
        years[num_years] = year;
        num_years += 1;
        return;
    }

    int i;
    for (i = 0; i < 10; i ++) {
        if (used[i]) continue;
        if (dep + 1 == 1 && i == 0) continue;
        used[i] = 1;
        dfs(dep + 1, year * 10 + i);
        used[i] = 0;
    }
}

int main() {
    int in_year, next_year, index;
    num_years = 0;
    memset(used, 0, sizeof(int));
    dfs(0, 0);
    scanf("%d", &in_year);
    for (index = 0; index < num_years; index ++) {
        if (years[index] > in_year) break;
    }
    if (index == num_years) printf("10234");
    else printf("%d", years[index]);
    return 0;
}
