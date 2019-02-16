//
// Created by zhaopeng on 19-2-14.
//

#include <stdio.h>
#include <queue>

using namespace std;

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
void preorder(node* root) {
    if (root == NULL) {
        return;

    }
    printf("%d\n", root);
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(node* root) {
    if (root == NULL) {
        return;

    }
    inorder(root->lchild);
    printf("%d\n", root->date);
    inorder(root->rchild);
}
void postorder(node* root) {
    if (root == NULL) {
        return;

    }
    inorder(root->lchild);
    inorder(root->rchild);
    printf("%d\n", root->date);
}

void Layerorder(node* root) {
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *now = q.front();
        q.pop();
        printf("%d", now->date);
        if (now->lchild != NULL) {
            q.push(now->lchild);
        }
        if (now->rchild != NULL) {
            q.push(now->rchild);
        }
    }
}

//当前先序遍历区间【preL,preR】,中序序列区间【inL，inR】

int pre[10010];
int in[10010];
node* create(int preL,int preR,int inL,int inR) {

    if (preL > preR) {
        return NULL;

    }
    node *root = new node;
    root->date = pre[preL];
    int k;
    for (k = inL; k <= inR; ++k) {
        if (in[k] == pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;

}