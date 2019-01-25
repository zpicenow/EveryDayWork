//
// Created by zhaopeng on 19-1-24.
//

/*
 * 归并排序
 */
#include <stdio.h>
//const int maxn = 100;
//void merge(int A[],int L1,int R1,int L2,int R2) {
//    int i = L1, j = L2, temp[maxn], index = 0;
//
//    while ((i < R1) && (j < R2)) {
//        if (A[i] <= A[j]) {
//            temp[index++] = A[i++];
//        } else {
//            temp[index++] = A[j++];
//        }
//    }
//    while (i <= R1) {
//        temp[index++] = A[i++];
//    }
//    while (j <= R2) {
//        temp[index++] = A[j++];
//    }
//    for (int k = 0; k < index; ++k) {
//        A[L1 + k] = temp[k];
//    }
//}
////递归的归并
//void mergeSort(int A[],int left,int right) {
//    if (left < right) {
//        int mid = (left + right) / 2;
//        mergeSort(A, left, mid);
//        mergeSort(A, mid + 1, right);
//        merge(A, left, mid, mid + 1, right);
//    }
//}
////非递归的归并
//void mergeSort(int A[]) {
//    for (int step = 2; (step / 2) <= n; step *= 2) {
//        for (int i = 1; i < n; i += step) {
//            int mid = i + step / 2 - 1;
//            if (mid + 1 <= n) {
//                merge(A, i, mid, mid + 1, min(i + step - 1, n));
//            }
//        }
//    }
//}
//
