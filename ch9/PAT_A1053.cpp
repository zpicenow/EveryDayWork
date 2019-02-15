//
// Created by zhaopeng on 19-2-15.
//

/*
 * PAT A1053
 * Given a non-empty tree with root R, and with weight W​i​​ assigned to each tree node T​i​​. The weight of a path from R to L is defined to be the sum of the weights of all the nodes along the path from R to any leaf node L.
 * Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number. For example, let's consider the tree showed in the following figure: for each node,
 * the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node. Suppose that the given number is 24,
 * then there exists 4 different paths which have the same given weight:
 * {10 5 2 7}, {10 4 10}, {10 3 3 6 2} and {10 3 3 6 2}, which correspond to the red edges in the figure.
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 110;
struct node {
    int weight;
    vector<int> child;
}Node[MAXN];
bool cmp(int a,int b) {
    return Node[a].weight > Node[b].weight;
}
int n,m,S;
int path[MAXN];

void DFS(int index,int numNode,int sum) {
    if (sum > S) {
        return;
    }
    if (sum == S) {
        if (Node[index].child.size() != 0) {
            return;
        }
        for (int i = 0; i < numNode; ++i) {
            printf("%d", Node[path[i]].weight);
            if (i < numNode - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
        return;
    }

    for (int i = 0; i < Node[index].child.size(); ++i) {
        int child = Node[index].child[i];
        path[numNode] = child;
        DFS(child, numNode + 1, sum + Node[child].weight);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &S);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &Node[i].weight);
    }
    int id,k,child;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child);
            Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);
    }
    path[0] = 0;
    DFS(0, 1, Node[0].weight);
    return 0;
}