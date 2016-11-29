#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int i,j,c1,c2;
    int tmp;
    int card[52];
    char color[] = {'S','H','D','C'};
    char number[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int player[4];
    for (i=0; i<52; i++){
        card[i]=i;
    }
    srand(time(NULL));
    for(i=0; i<1000; i++){
        c1 = rand() % 52;
        c2 = rand() % 52;
        tmp = card[c1];
        card[c1] = card[c2];
        card[c2] = tmp;
    }
    for(i=0; i<4; i++){
        player[i] = 0;
    }
    for(j=0; j<2; j++){
        for(i=0; i<4; i++){
            player[i] = player[i] + (card[i + (j * ( j + 3))] % 13 + 1);
        }
    }
    for(i=0; i<4; i++){
        printf("player %d\n", i+1);
        printf("sum is %d ", player[i]);
        for(j=0; j<2; j++){
            printf("%c%c ", color[card[i + (j * (j + 3))] / 13],number[card[i +( j * (j + 3))] % 13]);
        }
        printf("\n");
    }
}