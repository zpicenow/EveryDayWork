//
// Created by zhaopeng on 19-2-16.
//

/*
 * 二叉搜索树
 */

#include <stdio.h>

struct node{
    int  date;
    node* lchild;
    node* rchild;
};
node* newNode(int x) {
    node* Node = new node;
    Node->date = x;
    Node->lchild = NULL;
    Node->rchild = NULL;
    return Node;
}

void search(node* root,int x) {
    if (root == NULL) {
        printf("fail");
        return;
    }
    if (x == root->date) {
        printf("%d", root->date);

    } else if (x < root->date) {
        search(root->lchild,x);
    } else {
        search(root->rchild, x);
    }
}

void insert(node* root,int x) {
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if (x == root->date) {
        return;
    } else if (x < root->date) {
        insert(root->lchild, x);
    } else {
        insert(root->rchild, x);
    }

}

node * create(int date[],int n) {
    node *root = NULL;
    for (int i = 0; i < n; ++i) {
        insert(root, date[i]);
    }
    return root;
}

//寻找以root为根的树中最大节点
node *findMAX(node *root) {
    while (root->rchild != NULL) {
        root = root->rchild;
    }
    return root;
}

//寻找以root为根的树中最小节点
node *findMIN(node *root) {
    while (root->lchild != NULL) {
        root = root->lchild;
    }
    return root;
}

void deleteNode(node *root, int x) {
    if (root == NULL) {
        return;

    }
    if (root->date == x) {
        if (root->lchild == NULL && root->rchild == NULL) {
            root = NULL;
        } else if (root->lchild != NULL) {
            node *pre = findMAX(root->lchild);
            root->date = pre->date;
            deleteNode(root->lchild, pre->date);
        } else {
            node *next = findMIN(root->rchild);
            root->date = next->date;
            deleteNode(root->rchild, next->date);
        }
    } else if (root->date > x) {
        deleteNode(root->lchild, x);
    } else {
        deleteNode(root->rchild, x);
    }
}