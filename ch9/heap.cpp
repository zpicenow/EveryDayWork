//
// Created by zhaopeng on 19-2-21.
//

/*
 * 堆
 */

#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100;
int heap[maxn], n = 10;

void downAdjust(int low, int high) {   //堆的数组范围[low,high]
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 >= high && heap[j + 1] > heap[j]) {
            j = j + 1;
        }
        if (heap[j] > heap[i]) {
            swap(heap[i], heap[j]);
            i = j;
            j *= 2;
        } else {
            break;
        }
    }
}

void createHeap() {
    for (int i = n / 2; i >= 0; --i) {
        downAdjust(i, n);
    }
}
int top() {
    int top = heap[0];
    heap[0] = heap[n--];    //注意删除元素后个数减一
    downAdjust(0, n);
    return top;
}

void upAdjust(int low ,int high) {
    int i = high, j = high / 2;
    while (j >= low) {
        if (heap[j] < heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j /= 2;
        } else {
            break;
        }
    }
}

void insert(int x) {
    heap[++n] = x;
    upAdjust(0, n);
}

void heapSort() {
    createHeap();
    for (int i = n; i > 0; --i) {
        swap(heap[i], heap[0]);
        downAdjust(0, i - 1);
    }
}