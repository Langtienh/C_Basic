#include <stdio.h>

int n, m, d[100];

void print(){
    for (int i = 1; i <= n; i++)
        printf("%d", d[i]);
    printf("\n");
}

void try1(int cnt, int s) {
    if (s == 0) return;
    if (cnt == n){
        d[cnt] = s;
        print(); return;
    }
    for (int i = 1; i <= s; i++){
        d[cnt] = i; try1(cnt + 1, s - i);
    }
}

int main(){
    printf("Nhap n va m: ");
    scanf("%d%d", &n, &m);
    printf("Cac nghiem nguyen duong cua m la: \n");
    try1(1, m);
    return 0;
}