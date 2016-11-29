#include <stdio.h>
#include <math.h>
int main() {
    srand(time(NULL));
    int a = 0, b = 0, tmp, answer[4], i, input[4];
    for (i = 0; i < 4; i++) {
        while (tmp == answer[0] || tmp == answer[1] || tmp == answer[2] || tmp == answer[3]){
            tmp = rand() % 9 + 1;
    }
    answer[i] = tmp;
    }
    for (i = 0; i < 4; i++){
        printf("%d", answer[i]);
    }
    printf("\n");
    while (a != 4){
        a = 0, b = 0;
        for (i = 0; i < 4; i++){
            
		}
	}
}