//
// Created by zhaopeng on 19-1-27.
//

///*
// * PAT A 1059
// * 分解质因子 Prime factor
// */
//#include <stdio.h>
//#include <math.h>
//
//const int maxn = 100010;
//bool isPrime(int n) {
//    if (n == 1)return false;
//    int sqr = static_cast<int>(sqrt(1.0 * n));
//    for (int i = 2; i <= sqr; ++i) {
//        if (n % i == 0) {
//            return false;
//
//        }
//    }
//    return true;
//}
//
//int prime[maxn], pNum = 0;
//void Find_Prime() {
//    for (int i = 1; i < maxn; ++i) {
//        if (isPrime(i)) {
//            prime[pNum++] = i;
//        }
//    }
//}
//
//struct factor {
//    int x, cnt;
//
//} fac[10];
//int main() {
//    Find_Prime();
//    int n, num = 0;
//    scanf("%d", &n);
//    if (n == 1) {
//        printf("1=1");
//
//    } else {
//        printf("%d=", n);
//        int sqr = static_cast<int>(sqrt(1.0 * n));
//        for (int i = 0; i < pNum && prime[i] <= sqr; ++i) {
//            if (n % prime[i] == 0) {
//                fac[num].x = prime[i];
//                fac[num].cnt = 0;
//                while (n % prime[i] == 0) {
//                    fac[num].cnt++;
//                    n /= prime[i];
//                }
//                num++;
//            }
//            if (n == 1) {
//                break;
//            }
//        }
//        if (n != 1) {
//            fac[num].x = n;
//            fac[num++].cnt = 1;
//        }
//    }
//
//    for (int j = 0; j < num; ++j) {
//        if (j > 0) {
//            printf("*");
//            printf("%d", fac[j].x);
//            if (fac[j].cnt > 1) {
//                printf("^%d", fac[j].cnt);
//
//            }
//        }
//    }
//    return 0;
//}