//
// Created by zhaopeng on 19-1-21.
//

/*
 * PAT B1009 说反话，将给定的句子中的单词反序
 */
#include <stdio.h>
int main(){
    char str[90][90];
    int num = 0;
    while (scanf("%s", str[num]) != EOF) {
        num++;
    }
    for (int i = num - 1; i > -1; --i) {
        printf("%s", str[i]);
        if (i != 0) {
            printf(" ");
        }
    }


}