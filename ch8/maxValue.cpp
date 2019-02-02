//
// Created by zhaopeng on 19-2-2.
//

/*
 * 有n件物品，每件物品的重量为w(i)，价值为c(i)，现在需要选出若干件物品放入容积为V的背包内，使得总价值最大
 */

#include <stdio.h>

const int maxn = 30;
int n, V, maxValue = 0;
int w[maxn], c[maxn];
void DFS(int index,int sumW,int sumC) {
    if (index == n) {
        if (sumW <= V && sumC > maxValue) {
            maxValue = sumC;
        }
        return;
    }
    DFS(index + 1, sumW, sumC);
    DFS(index + 1, sumW + w[index], sumC + c[index]);
}
int main(){
    scanf("%d%d", &n, &V);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    DFS(0, 0, 0);
    printf("%d\n", maxValue);
    return 0;
}
//优化后
void DFS1(int index,int sumW,int sumC) {
    if (index == n) {
        return;

    }
    DFS1(index + 1, sumW, sumC);
    if (sumW + w[index] <= V) {
        if (sumC + c[index] > maxValue) {
            maxValue = sumC + c[index];
        }
        DFS1(index + 1, sumW + w[index], sumC + c[index]);
    }
}