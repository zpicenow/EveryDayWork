//
// Created by zhaopeng on 19-1-23.
//

/*
 * PAT B 1020 月饼
 */
//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//const int MAX = 1001;
//struct MOON {
//    double store;
//    double sell;
//    double price;
//};
//
//bool cmp(MOON m1, MOON m2) {
//    return m1.price > m2.price;
//}
//int main(){
//    int n;
//    double total;
//    scanf("%d%lf", &n, &total);
//    MOON moon[MAX];
//    for (int i = 0; i < n; ++i) {
//        scanf("%lf", &moon[i].store);
//    }
//    for (int j = 0; j < n; ++j) {
//        scanf("%lf", &moon[j].sell);
//
//    }
//    for (int k = 0; k < n; ++k) {
//        moon[k].price = moon[k].sell / moon[k].store;
//    }
//
//    double value = 0.0;
//    sort(moon, moon + n, cmp);
//    for (int l = 0; (l < n)&&(total > 0); ++l) {
//        if (total <= moon[l].store) {
//            value +=  moon[l].price * total;
//            total = 0;
//        } else {
//            value += moon[l].sell;
//            total -= moon[l].store;
//        }
//    }
//    printf("%.2f", value);
//}