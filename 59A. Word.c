#include <stdio.h>
#include <stdbool.h>
#define LEN 110

bool is_low(char c){
    if (c < 'a') return false;
    if (c > 'z') return false;
    return true;
}

char to_up(char c) {
    return c + 'A' - 'a';
}

char to_low(char c) {
    return c + 'a' - 'A';
}

void upper(char* str_in, char* str_high)
{
    int len = strlen(str_in);
    int i;
    for (i = 0; i < len; i++) {
        if (is_low(str_in[i])) {
            str_high[i] = to_up(str_in[i]);
        } else {
            str_high[i] = str_in[i];
        }
    }
    str_high[len] = '\0';
    return;
}


void lower(char* str_in, char* str_low)
{
    int len = strlen(str_in);
    int i;
    for (i = 0; i < len; i++) {
        if (is_low(str_in[i])) {
            str_low[i] = str_in[i];
        } else {
            str_low[i] = to_low(str_in[i]);
        }
    }
    str_low[len] = '\0';
    return;
}

int count_low(char *str_in){
    int cnt = 0;
    int len = strlen(str_in);
    int i;
    for (i = 0; i < len; i ++) {
        if (is_low(str_in[i])) cnt ++;
    }
    return cnt;
}


int main()
{
    int cnt_high, cnt_low, len;
    char *str_in[LEN], *str_high[LEN], *str_low[LEN];

    scanf("%s", str_in);

    len = strlen(str_in);
    cnt_low = count_low(str_in);
    cnt_high = len - cnt_low;

    if (cnt_high > cnt_low) {
        upper(str_in, str_high);
        printf("%s", str_high);
    } else {
        lower(str_in, str_low);
        printf("%s", str_low);
    }

    return 0;
}
