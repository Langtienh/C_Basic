#include<stdio.h>

int n, b[11], hoanVi[10];

void print(){
    for (int i = 0; i < n; i++)
        printf("%d ", hoanVi[i]);
    printf("\n");
}

void khoiTao(){
    for (int i = 0; i <= n; i++)
        b[i] = 0;
}

void Try(int cnt){
    if (cnt == n){
        print(); return;
    }
    for (int i = 1; i <= n; i++){
        if (!b[i]){
            b[i] = 1;
            hoanVi[cnt] = i;
            Try(cnt + 1);
            b[i] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    khoiTao();
    Try(0);
    return 0;
}
