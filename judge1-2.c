#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    // all全班 many轉走的人數 randnum是亂數
    int all, many, i, j, randnum;
    scanf("%d %d", &all, &many);
    int who[many]; // 轉學的號碼回存在who
    int sit[all]; // 座位
    for (i = 0; i < many; i++){
        scanf("%d", &who[i]);
    }
    srand(time(NULL));
    for (i = 0; i < all; i++){
        randnum = (rand() % all) + 1; // 取亂數
        sit[i] = randnum;
        for (j = 0; j < i; j++){ // 檢查有無重複
            if (sit[j] == randnum) {
                i--;
            }
        }
    }
    for (i = 0; i < all; i++){ // 印出沒轉學的
        if (i % 7 == 0 && i > 0) // 七個換行
            printf("\n");
        printf("%2d ", sit[i]);
    }
    printf("\n");
    for (i = 0; i < many; i++){ // 找到轉學的人
        for (j = 0; j < all; j++){
            if (sit[j] == who[i]){ // 跟who做比對確定有無轉學
                sit[j] = - 1; // 轉學做記號
                break;
            }
        }
    }
    for (i = 0; i < all; i++){ 
        if (i % 7 == 0) // 七個換行
            printf("\n");
        if (sit[i] > 0){ // 判斷有無轉學
            printf("%2d ", sit[i]);
        } else { // 轉學印叉叉
            printf("XX ");
        }
    }
    return 0;
}