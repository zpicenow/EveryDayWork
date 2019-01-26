//
// Created by zhaopeng on 19-1-26.
//

/*
 * 分数
 */

#include <math.h>
#include <cstdio>

struct Fraction {
    int up,down;
};
int gcd(int a,int b) {
    if (b == 0) {
        return a;
    } else return gcd(a, a % b);

}
Fraction reduction(Fraction result) {
    if (result.down < 0) {
        result.down = -result.down;
        result.up = -result.up;

    }
    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}
//分数加法
Fraction add(Fraction f1,Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;

    return reduction(result);
}
//减法
Fraction minu(Fraction f1,Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;

    return reduction(result);
}

//分数乘法
Fraction mul(Fraction f1,Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}
//分数除法
Fraction div(Fraction f1,Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

void showResult(Fraction r) {
    r = reduction(r);
    if (r.down == 1) {
        printf("%d", r.up);
    } else if (abs(r.up) > r.down) {
        printf("%d %d/%d", r.up / r.down, abs(r.up) % r.down, r.down);

    } else {
        printf("%d/%d", r.up, r.down);
    }
}
