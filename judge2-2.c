#include<stdio.h>
int main() {
    int i, j, m ,n;
    int price; // �R�F�誺����
    scanf("%d", &price);
    int quantity[4]; // �w���ƶq
    for (i = 0; i < 4; i++){
        scanf("%d", &quantity[i]);
    }
    // �U�صw���b�̭������p�U�A�C�صw�����q
    int coin_max_qua = 0;
    int coin_50;
    int coin_10;
    int coin_5;
    int coin_1;
    for (i = 0; i <= quantity[0]; i++){
        for (j = 0; j <= quantity[1]; j++){
            for (m = 0; m <= quantity[2]; m++){
                for (n = 0; n <= quantity[3]; n++){
                    int money = i * 50 + j * 10 + m * 5 + n * 1; // ��e���B
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
        printf("���I�G$50: %d��, $10: %d��, $5: %d��, $1: %d��\n", coin_50, coin_10, coin_5, coin_1);
        printf("���q�G%fg\n", 10*coin_50 + 7.5*coin_10 + 4.4*coin_5 + 3.8*coin_1);
    } else {
        printf("�S�����i�H�I�C\n");
    }
}