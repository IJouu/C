#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void create_student(int *number_boy, int *height_boy, int *number_girl, int *height_girl, int *boy_count, int *girl_count, int *n) {
    int tmp_height, i;
    srand(time(NULL) + getpid());
    for (i = 1; i <= *n; i++){
        int sex_judge = rand() % 2; // �üƲ��ͩʧO
        // �k�ͪ������O300~400�A�k�ͪ������O400~500
        if (sex_judge == 0 ){
            tmp_height = (rand() % 100) + 300;
            number_girl[*girl_count] = i;
            height_girl[*girl_count] = tmp_height;
            *girl_count = *girl_count + 1;
        } else {
            tmp_height = (rand() % 100) + 400;
            number_boy[*boy_count] = i;
            height_boy[*boy_count] = tmp_height;
            *boy_count = *boy_count + 1;
        }
    }
}
void print_student(int *number, int *height, int *count){
    int i;
    for(i = 0; i < *count; i++){
        printf("No.%2d, Height: %d\n", number[i], height[i]);
    }
}
// �Q�δ��J�ƧǪk�ƧǨ����C�]�������P�y���O�@�ժ��A�ҥH�ഫ�ɡA�y���]�n�@�_���ഫ�C
void sort_student(int *number, int *height, int *count){
    int i, j, tmp_num, tmp_height;
    for (i = 1 ; i <= *count - 1; i++) {
        j = i;
        while ( j > 0 && height[j] < height[j-1]) {
            tmp_height = height[j];
            tmp_num = number[j];
            height[j] = height[j-1];
            number[j] = number[j-1];
            height[j-1] = tmp_height;
            number[j-1] = tmp_num;
            j--;
        }
    }
}
int main() {
    int n, i;
    scanf("%d", &n); // ���Z�X�ӤH
    int number_boy[n]; // �k�ͮy��
    int height_boy[n]; // �k�ͨ���
    int number_girl[n]; //�k�ͮy��
    int height_girl[n]; // �k�ͨ���    
    int boy_count = 0;
    int girl_count = 0;
    create_student(number_boy, height_boy, number_girl, height_girl, &boy_count, &girl_count, &n);
    printf("�k��%d�H\n", boy_count);
    printf("�k��%d�H\n", girl_count);
    // �L�X���ƧǪ��k�k�͡C
    // printf("\nboy\n");
    // print_student(number_boy, height_boy, &boy_count);

    // printf("\ngirl\n");
    // print_student(number_girl, height_girl, &girl_count);

    // �ƧǡA�æL�X�C
    sort_student(number_boy, height_boy, &boy_count);
    sort_student(number_girl, height_girl, &girl_count);
    printf("\n----- Boy -----\n");
    print_student(number_boy, height_boy, &boy_count);
    printf("\n----- Girl -----\n");
    print_student(number_girl, height_girl, &girl_count);
}