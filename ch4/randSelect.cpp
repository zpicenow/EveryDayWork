//
// Created by zhaopeng on 19-1-25.
//
///*
// * 随机选择算法
// */
//#include <stdio.h>
//int randParitition(int A[],int left,int right) {
//    int temp = A[left];
//    while (left < right) {
//        while ((left < right) && (A[right] < temp)) {
//
//            --right;
//        }
//        A[left] = A[right];
//        while ((left < right) && (A[left] <= temp)) {
//            ++left;
//        }
//        A[right] = A[left];
//    }
//    A[left] = temp;
//    return left;
//}
//int randSelect(int A[], int left, int right, int K) {
//    if (left == right) {
//        return A[left];
//    }
//    int p = randParitition(A, left, right);
//    int M = p - left + 1;
//    if (K == M) {
//        return A[M];
//
//    } else if (M < K) {
//        return randSelect(A, p + 1, right, K - M);
//
//    } else {
//        return randSelect(A, left, p - 1, K);
//    }
//}
//
