#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int yes(int a[]){
    int i, sol = 0;
    for (i = 0; i < 5000; i++){
        if (a[i] == 1)
            sol++;
    }
    return sol;
}
int gift(int a[]) {
    int i, sol = 0;
    for (i = 999; i < 5000; i += 1000){
        if (a[i] == 1)
            sol++;
    }
    return sol;
}
int main() { 
    srand(time(NULL));
    int a[5000];
    int i;
    for (i = 0; i < 5000; i++){
        a[i] = (rand() % 2) + 1;
    }
    printf("��%d�ӤH���w\n", yes(a));
    printf("��%d�ӤH�����w\n", 5000 - yes(a));
    printf("�e�X%d��§��", gift(a));
    return 0;
}