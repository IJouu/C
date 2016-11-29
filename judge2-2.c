#include<stdio.h>
int main() {
    int i, j, m ,n;
    int price; // 買東西的價格
    scanf("%d", &price);
    int quantity[4]; // 硬幣數量
    for (i = 0; i < 4; i++){
        scanf("%d", &quantity[i]);
    }
    // 各種硬幣在最重的狀況下，每種硬幣的量
    int coin_max_qua = 0;
    int coin_50;
    int coin_10;
    int coin_5;
    int coin_1;
    for (i = 0; i <= quantity[0]; i++){
        for (j = 0; j <= quantity[1]; j++){
            for (m = 0; m <= quantity[2]; m++){
                for (n = 0; n <= quantity[3]; n++){
                    int money = i * 50 + j * 10 + m * 5 + n * 1; // 當前金額
                    if (money == price){
                        int tmp_coin_qua = i + j + m + n;
                        if(tmp_coin_qua > coin_max_qua){
                            coin_max_qua = tmp_coin_qua;
                            coin_50 = i;
                            coin_10 = j;
                            coin_5 = m;
                            coin_1 = n;
                        }
                    }
                }
            }
        }
    }
    if (coin_max_qua != 0){
        printf("應付：$50: %d個, $10: %d個, $5: %d個, $1: %d個\n", coin_50, coin_10, coin_5, coin_1);
        printf("重量：%fg\n", 10*coin_50 + 7.5*coin_10 + 4.4*coin_5 + 3.8*coin_1);
    } else {
        printf("沒有錢可以付。\n");
    }
}