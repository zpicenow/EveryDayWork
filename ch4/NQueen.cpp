//
// Created by zhaopeng on 19-1-23.
//

/*
 * n皇后问题
 */
//#include <stdio.h>
//#include <math.h>
//const int MAX = 10000;
//int n, p[MAX], hashTable[MAX] = {false};
//int count = 0;
//void generateP(int index) {
//    if (index == n + 1) {   //  递归边界，生成一个合法方案
//        count++;    //能到达这里的一定是合法方案
//        return;
//    }
//
//    for (int i = 1; i <= n; ++i) {  //第i行
//        if (hashTable[i] == 0) {    //第i行还没有皇后
//            bool flag = true;   //flag为true表示当前皇后不会和其他皇后冲突
//            for (int pre = 1; pre < index; ++pre) { //遍历之前的皇后
//                //第index列的皇后行号为i，第pre列的皇后行号为p[pre]
//                if (abs(index - pre) == abs(i - p[pre])) {
//                    flag = false;   //在一条对角线
//                    break;
//                }
//
//
//            }
//            if (flag) { //可以把皇后放在第i行
//
//                p[index] = i;   //另index列的皇后行号为i
//                hashTable[i] = true;    //第i行已经被占用
//                generateP(index + 1);
//                hashTable[i] = false;
//            }
//
//        }
//    }
//}
//int main() {
//    n = 8;
//    generateP(1);
//    printf("%d", count);
//    return 0;
//}