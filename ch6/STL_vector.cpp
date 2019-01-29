//
// Created by zhaopeng on 19-1-28.
//
/*
 * 杂项
 *
 */
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
int main() {
    vector<int> vi;
    map<string,int> mp;

    mp.insert(make_pair("hhh", 342));
}

struct fruit {
    string name;
    int price;

    friend bool operator<(fruit f1, fruit f2) {
        return f1.price < f2.price;
    }

};

struct cmp {
    bool  operator()(fruit f1,fruit f2) {
        return f1.price > f2.price;
    }
};

//此时定义方式必须是第三个参数写cmp
priority_queue<fruit, vector<fruit>, cmp> q;

