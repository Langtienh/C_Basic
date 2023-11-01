#include <stdio.h>
#include <string.h>

#define ll long long

int n, b[100];

void print(){
    for (int i = 0; i < n; i++)
        printf("%d", b[i]);
    printf("\n");
}

void try1(int cnt){
    if (cnt == n){
        print(); return;
    }
    try1(cnt + 1);
    b[cnt] = 1;
    try1(cnt + 1);
    b[cnt] = 0;
}

int main(){
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Cac xau nhi phan co do dai %d la:\n", n);
    memset(b, 0, sizeof(b));
    try1(0);
    return 0;
}