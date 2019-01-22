//
// Created by zhaopeng on 19-1-22.
//

/*
 * 给出N个字符串（由恰好三位大写字母组成），再给除M个查询字符串，问每个查询字符串出现的次数
 */
#include <stdio.h>

const int maxn = 100;
char S[maxn][5], temp[5];
int hashTable[26 * 26 * 26 + 10];
int hashFun(char s[], int len){
    int id = 0;
    for(int i = 0;i < len;++i){
        id = id * 26 + (s[i]-'A');
    }
    return id;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", S[i]);
        int id = hashFun(S[i], 3);
        hashTable[id]++;
    }
    for (int j = 0; j < m; ++j) {
        scanf("%s", temp);
        int id = hashFun(temp, 3);
        printf("%d\n", hashTable[id]);
    }
    return 0;
}