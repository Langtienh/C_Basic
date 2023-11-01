#include <stdio.h>

int n, k, a[20], b[20];

void print(){
    for (int i = 0; i < k; i++)
        printf("%d", a[i]);
    printf("\n");
}

void try1(int cnt){
    if (cnt == k){
        print();
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!b[i]){
            a[cnt] = i;
            b[i] = 1;
            try1(cnt + 1);
            b[i] = 0;
        }
    }
}


int main(){
    printf("Nhap n va k\n");
    scanf("%d%d", &n, &k);
    printf("Cac Hoan vi %d Chap %d la:\n", n, k);
    try1(0);
    return 0;
}
