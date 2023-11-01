#include <stdio.h>

int cnt = 0;
void move(int n, char A, char B, char C){
    if(n == 1){
    cnt++;
    printf("B%d: %c -> %c\n",cnt,A,B);
    } else {
    move(n-1,A,C,B);
    move(1,A,B,C);
    move(n-1,C,B,A);
    }
}

int main(){
    int n;
    printf("Nhap thap co do cao n: ");
    scanf("%d", &n);
    move(n,'A','B','C');
    return 0;
}