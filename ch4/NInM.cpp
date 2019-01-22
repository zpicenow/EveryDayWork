//
// Created by zhaopeng on 19-1-22.
//

/*
 * m,n < 1 e5
 * 判断n个数中是否出现在m中
 * 空间换时间
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool maxN[10010] = {false};
//int main(){
//    int n, m;
//    int num;
//    vector<int> Nv;
//    scanf("%d%d", &n, &m);
//    for (int i = 0; i < m; ++i) {
//        scanf("%d", &num);
//        maxN[num] = true;
//    }
//    for (int j = 0; j < n; ++j) {
//        scanf("%d", &num);
//        if (maxN[num]) {
//            Nv.push_back(num);
//        }
//    }
//    for (int k = 0; k < Nv.size() - 1; ++k) {
//        printf("%d ", Nv.at(k));
//    }
//    printf("%d", Nv.at(Nv.size()-1));
//}