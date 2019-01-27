//
// Created by zhaopeng on 19-1-26.
//

/*
 * 素数
 */
#include <cstdio>
#include <math.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


//素数筛法
const int maxn = 101;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};
void Find_Prime() {
    for (int i = 2; i < maxn; ++i) {
        if (!p[i]) {
            prime[pNum++] = i;
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}