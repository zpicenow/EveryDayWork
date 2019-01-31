//
// Created by zhaopeng on 19-1-31.
//

/*
 * PAT A 1032
 */

#include <stdio.h>
#include <cstring>

const int maxn = 100010;
struct NODE {
    char data;
    int next;
    bool flag;
} node[maxn];

int main() {
    for (int i = 0; i < maxn; ++i) {
        node[i].flag = false;
    }
    int s1, s2, n;
    scanf("%d %d %d", &s1, &s2, &n);
    int address, next;
    char data;
    for (int j = 0; j < n; ++j) {
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }
    int p;
    for (p = s1; p != -1; p = node[p].next) {
        node[p].flag = true;
    }
    for (p = s2; p != -1; p = node[p].next) {
        if (node[p].flag) {
            break;
        }

    }
    if (p != -1) {
        printf("%05d\n", p);
    } else {
        printf("-1\n");
    }
    return 0;
}