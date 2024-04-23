#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <utility>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {return b ? gcd(b, a%b): a;}
int gcd(int a, int b) {return b ? gcd(b, a%b): a;}



#define LEN 1001000
int a[LEN];
int sort_a[LEN], index[LEN];


struct seg{
    int head, tail;
    int left_child, right_child;
    int val;
}node[LEN*2];

void build_tree(int index, int head, int tail) {

    node[index].head = head;
    node[index].tail = tail;
    node[index].val = 0;

    if(head == tail) {
        node[index].left_child = -1;
        node[index].right_child = -1;
        return;
    } else {
        node[index].left_child = index * 2;
        node[index].right_child = index * 2 + 1;
        int mid = (head + tail) / 2;
        build_tree(node[index].left_child, head, mid);
        build_tree(node[index].right_child, mid+1, tail);
        return;
    }
}

void tree_update(int index, int head, int tail, int val) {
    if(head == node[index].head && tail == node[index].tail) {
        node[index].val = max(node[index].val, val);
        return;
    }
    int mid = (node[index].head + node[index].tail) / 2;
    if(mid >= tail) {
        tree_update(node[index].left_child, head, tail, val);
        return;
    }
    if(mid < head) {
        tree_update(node[index].right_child, head, tail, val);
        return;
    }
    tree_update(node[index].left_child, head, mid, val);
    tree_update(node[index].right_child, mid+1, tail, val);
    return;
}

int tree_query(int index, int q_index) {
    if(node[index].head == node[index].tail) {
        return node[index].val;
    }
    int mid = (node[index].head + node[index].tail) / 2;
    if(q_index <= mid) {
        node[node[index].left_child].val = max(node[node[index].left_child].val, node[index].val);
        node[node[index].right_child].val = max(node[node[index].right_child].val, node[index].val);
        node[index].val = 0;
        return tree_query(node[index].left_child, q_index);
    } else {
        node[node[index].left_child].val = max(node[node[index].left_child].val, node[index].val);
        node[node[index].right_child].val = max(node[node[index].right_child].val, node[index].val);
        node[index].val = 0;
        return tree_query(node[index].right_child, q_index);
    }


}

int main() {
    int n;
    int i,j, res, temp;
    while(scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i ++) {
            scanf("%d", a + i);
            sort_a[i] = a[i];
        }
        sort(sort_a, sort_a + n);
        unique(sort_a, sort_a + n);
        for(i = 0; i < n; i ++) {
            j = lower_bound(sort_a, sort_a+n, a[i]) - sort_a + 1;
            a[i] = j;
        }

        //for(i = 0; i < n; i ++)        printf("%d\t", a[i]);
        //printf("\n");

        build_tree(1, 0, n);

        res = 0;
        for(i = 0; i < n; i ++) {
            temp = tree_query(1, a[i] - 1) + 1;
            res = max(res, temp);
            tree_update(1, a[i], n, temp);
        }
        printf("%d\n", res);

    }

    return 0;
}
