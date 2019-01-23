//
// Created by zhaopeng on 19-1-23.
//

/*
 * 全排列，以n=3为例，体会分治递归思想
 */
#include <stdio.h>
//const int MAX = 11;
//int n, p[MAX], hashTable[MAX] = {false};
//
//void generateP(int index) {
//    if (index == n + 1) {
//        for (int i = 1; i <= n; ++i) {
//            printf("%d", p[i]);
//        }
//        printf("\n");
//        return;
//    }
//    for (int j = 1; j <= n; ++j) {
//        if (hashTable[j] == 0) {
//            p[index] = j;
//            hashTable[j] = true;
//            generateP(index + 1);
//            hashTable[j] = false;
//        }
//    }
//}
//int main() {
//    n = 3;
//    generateP(1);
//    return 0;
//}