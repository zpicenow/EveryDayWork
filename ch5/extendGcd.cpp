//
// Created by zhaopeng on 19-1-27.
//

/*
 * 拓展欧几里得算法
 */
#include <stdio.h>

int exGcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exGcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - a / b * y;
    return g;
}