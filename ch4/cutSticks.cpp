//
// Created by zhaopeng on 19-1-24.
//

/*
 * 切割木棒问题
 *给出N根木棒，长度均已知，现通过切割他们，得到至少K段长度相等的木棒（长度必须是整数），问长度相等的木棒最长能有多长
 *比如三根长度分别为10,24,15的木棒，希望K值为7，求最大长度
 */
//#include <stdio.h>
//
//const int MAX = 100;
//int stick[MAX] = {0};
//int n, k;
//
//int solve(int L, int R, int K) {
//    int mid, count = 0;
//    while (L + 1 < R) {
//
//        count = 0;
//        mid = (L + R) / 2;
//        for (int i = 0; i < n; ++i) {
//            count += stick[i] / mid;
//        }
//        if (count < K) {
//            R = mid;
//        } else {
//            L = mid;
//        }
//    }
//    return mid;
//}
//
//int main() {
//    int maxL = -1;
//    scanf("%d%d", &n, &k);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &stick[i]);
//        if (stick[i] > maxL) {
//            maxL = stick[i];
//        }
//    }
//    printf("%d", solve(1, maxL, k) - 1);
//
//    return 0;
//
//}

