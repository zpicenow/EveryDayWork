//
// Created by zhaopeng on 19-2-18.
//

/*
 * 并查集
 */

#include <stdio.h>
int father[10010] = {0};
int findFather1(int x) {
    while (x != father[x]) {
        x = father[x];
    }
    return x;
}

void Union(int a,int b) {
    int faA = findFather1(a);
    int faB = findFather1(b);
    if (faA != faB) {
        father[faA] = faB;
    }
}

//int findFather(int x) {
//    int a = x;
//    while (x != father[x]) {
//        x = father[x];
//    }
//    while (a != father[a]) {
//        int z = a;
//        a = father[a];
//        father[z] = x;
//    }
//    return x;
//
//}

//递归
int findFather(int x) {
    if (x == father[x]) {
        return x;
    } else {
        int F = findFather(father[x]);
        father[x] = F;
        return F;

    }

}