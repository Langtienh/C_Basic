#include <stdio.h>

int n, k, a[20], b[20];

void print(){
    for (int i = 1; i <= k; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void try1(int v, int cnt){
    a[cnt] = v;
    if (cnt == k){
        print();
        return;
    }
    for (int i = v + 1; i <= n; i++){
        try1(i, cnt + 1);
    }
}

int main(){
    printf("Nhap n va k:\n");
    scanf("%d%d", &n, &k);
    printf("Cac to hop %d chap %d la:\n", n, k);
    try1(1, 1);
    return 0;
}

