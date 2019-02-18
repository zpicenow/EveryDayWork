//
// Created by zhaopeng on 19-2-18.
//

/*
 * 并查集
 */

#include <stdio.h>
int father[10010] = {0};
int findFather(int x) {
    while (x != father[x]) {
        x = father[x];
    }
    return x;
}

void Union(int a,int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faA] = faB;
    }
}