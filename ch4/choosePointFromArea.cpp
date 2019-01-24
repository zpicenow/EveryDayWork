//
// Created by zhaopeng on 19-1-23.
//

/*
 * 区间选点问题
 * 给出N个闭区间[x,y]，求最少需要确定多少个点，才能使每个闭区间中都至少存在一个点
 */
//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//const int MAX = 110;
//struct AREA {
//    int x, y;
//
//} area[MAX];
//
//bool cmp(AREA a1, AREA a2) {    //左端点从大到小排序，左端点相同，右端点从小到大排序
//    if (a1.x != a2.x) {
//        return a1.x > a2.x;
//    } else {
//        return a1.y < a2.y;
//    }
//}
//int main() {
//    int n;
//    scanf("%d", &n);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d%d", &area[i].x, &area[i].y);
//
//    }
//    sort(area, area + n, cmp);
//    int ans = 1, lastX = area[0].x;     //ans记录不相交区间个数，lastX记录上一个被选中的区间左端点
//    for (int j = 1; j < n; ++j) {
//        if (area[j].y < lastX) {
//            lastX = area[j].x;
//            ++ans;
//        }
//    }
//    printf("%d", ans);
//}
//


