//
// Created by zhaopeng on 19-1-27.
//
//


/*
 *
 * 大整数
 */

#include <stdio.h>
#include <cstring>

struct bigN {
    int d[1000];
    int len;

    bigN() {
        memset(d, 1000, sizeof(d));
        len = 0;
    }
};

//字符串到数组的逆位
bigN change(char str[]) {
    bigN a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; ++i) {
        a.d[i] = str[a.len - i - 1] - '0';
    }
}

int compare(bigN a, bigN b) {
    if (a.len > b.len) {
        return 1;
    } else if (a.len < b.len) {
        return -1;
    } else {
        for (int i = a.len - 1; i >= 0; --i) {
            if (a.d[i] > b.d[i]) {
                return 1;
            } else if (a.d[i], b.d[i]) {
                return -1;
            }
        }
        return 0;

    }
}

bigN add(bigN a, bigN b) {
    bigN c;
    int carry = 0;  //进位
    for (int i = 0; i < a.len || i < b.len; ++i) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}

bigN sub(bigN a,bigN b) {
    bigN c;
    for (int i = 0; i < a.len || i < b.len; ++i) {
        if (a.d[i] < b.d[i]) {
            --a.d[i + 1];
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}
//高精度与低精度乘法

bigN multi(bigN a,int b) {
    bigN c;
    int carry;
    for (int i = 0; i < a.len; ++i) {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry != 0) {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}
//高精度与低精度除法

bigN div(bigN a, int b,int &r) {        //r为余数
    bigN c;
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; --i) {
        r = r * 10 + a.d[i];
        if (r < b) {
            c.d[i] = 0;
        } else {
            c.d[i] = r / b;
            r %= b;
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;
    }
}