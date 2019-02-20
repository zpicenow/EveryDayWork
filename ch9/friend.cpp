//
// Created by zhaopeng on 19-2-20.
//

/*
 * 已知如果A和B是好朋友，等价于B和A是好朋友，如果A和C是好朋友，B和C也是好朋友，
 * 那么A和B也是好朋友。现给出一些人，问能够分成几组，使得每组之内两两都是好朋友，
 * 每组之间不存在好朋友,
 * 输入两个正整数n，m，n为人数，m为朋友对数，然后分别输入m行，每行是两个互为朋友的编号  ，输出组数
 */

#include <stdio.h>

const int N = 110;
int father[N];
bool isRoot[N];

int findFather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[a] = faB;

    }
}

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
        isRoot[i] = false;
    }
}

int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        Union(a, b);

    }
    for (int i = 1; i <= n; ++i) {
        isRoot[findFather(i)] = true;

    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += isRoot[i];
    }
    printf("%d\n", ans);
    return 0;

}
