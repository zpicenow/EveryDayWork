//
// Created by zhaopeng on 19-1-31.
//

/*
 * 链表
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    node *next;

};


node *create(int Array[]) {
    node *p, *pre, *head;
    head = new node;
    head->next = nullptr;
    pre = head;
    for (int i = 0; i < 5; ++i) {

        p = new node;
        p->data = Array[i];
        p->next = nullptr;
        pre->next = p;
        pre = p;
    }

    return head;


}

//查找元素
int search(node *head, int x) {
    int count = 0;
    node *p = head->next;
    while (p != nullptr) {
        if (p.data == x) {
            count++;
        }
        p = p->next;
    }
    return count;
}

//插入元素
void insert(node *head, int pos, int x) {
    node *p = head;
    for (int i = 0; i < pos - 1; ++i) {
        p = p->next;
    }
    node *q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;

}

//删除元素
void del(node *head, int x) {
    node *p = head->next;
    node *pre = head;
    while (p != nullptr) {
        if (p.data == x) {
            pre->next = p->next;
            delete (p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}