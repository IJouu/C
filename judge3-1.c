#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prime(int n){
    int i = n - 1;
    if (n == 1){
        return 0;
    }
    while (i > 1){
        if (n % i == 0){
            return 0;
        }
        i--;
    }
    return 1;
}
void sort(int data[], int n){
    int i, tmp, j;
    for (i = 1; i < n; i++){
        tmp = data[i];
        j = i - 1;
        while (j >= 0 && tmp > data[j]){
            data[i] = data[j];
            j = j - 1;
        }
        data[j + 1] = tmp;
    }
}
int main() {
    int head;
    int i, j;
    int other[5];
    srand(time(NULL));
    head = rand() % 55 + 1;
    while (prime(head) != 1){
        head = rand() %55 + 1;
    }
    for (i = 0; i < 5; i++) {
        other[i] = rand() %55 + 1;
        while (other[i] == head){
            other[i] = rand() %55 + 1;
        }
        for (j = i - 1; j >= 0; j++){
            if (other[i] == other[j]){
                i--;
                break;
            }
        }
    }
    // 排序
    sort(other, 5);
    printf("首獎 : %02d", head);
    printf("其他 : \n");
    for (i = 0; i < 5; i++){
        printf(" %02d", other[i]);
    }
}