//
// Created by zhaopeng on 19-2-3.
//

/*
 * 给出一个m*n的矩阵，矩阵中的元素为0或1，称位置(x,y)与其上下左右四个位置(x,y+1),(x-1,y),(x+1,y),(x,y-1)是相邻的，块的个数
 * 如果矩阵中有若干个1是相邻的，不必两两相邻，那么称这些1构成了一个块，求给定矩阵中
 */

#include <stdio.h>
#include <queue>

using namespace std;
const int maxn = 100;

struct node {
    int x, y;
} Node;

int n, m;
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};
int X[4] = {0, 0, 1 - 1};
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y) {
    if (x >= n || x < 0 || y >= m || y < 0) {
        return false;
    }
    if (matrix[x][y] == 0 || inq[x][y]) {
        return false;
    }
    return true;
}

void BFS(int x, int y) {
    queue<node> Q;
    Node.x = x;
    Node.y = y;
    Q.push(Node);
    inq[x][y] = true;
    while (!Q.empty()) {
        node top = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (judge(newX, newY)) {
                Node.x = newX, Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;

            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            scanf("%d", &matrix[x][y]);

        }
    }
    int ans = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (matrix[x][y] == 1 && !inq[x][y]) {
                ans++;
                BFS(x, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;

}
