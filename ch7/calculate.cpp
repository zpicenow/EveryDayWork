//
// Created by zhaopeng on 19-1-30.
//

/*
 * 四则运算计算器
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct node {
    double num;
    char op;
    bool flag;  //true表示操作数num，false表示操作符op

};

string str;
stack<node> s;
queue<node> q;
map<char, int> op;

//中缀转后缀
void change() {
    double num;
    node temp;
    for (int i = 0; i < str.length();) {
        if (str[i] >= '0' && str[i] <= '9') {
            temp.flag = true;
            temp.num = str[i++] - '0';
            while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            q.push(temp);
        } else {
            temp.flag = false;
            while (!s.empty() && op[str[i]] <= op[s.top().op]) {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

//计算后缀表达式
double cal() {
    double temp1, temp2;
    node cur,temp;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.flag == true) {
            s.push(cur);

        } else {
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            if (cur.op == '+') temp.num = (temp1 + temp2);
            else if (cur.op == '-')  temp.num = (temp1 - temp2);
            else if (cur.op == '*') temp.num = (temp1 * temp2);
            else temp.num = (temp1 / temp2);
            s.push(temp);
        }
    }
    return s.top().num;

}

int main() {
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin, str), str != "0") {
        for (string::iterator it = str.end(); it != str.begin(); --it) {
            if (*it == ' ') {
                str.erase(it);
            }

        }
        while (!s.empty()) {
            s.pop();

        }
        change();
        printf("%.2f\n", cal());
    }
    return 0;
}