#include <stdio.h>

#define ll long long

ll d[1000][1000];

ll try1(int n, int k){
    if (k == 0 || k == n) d[n][k] = 1;
    if (d[n][k]) return d[n][k];
    d[n][k] = try1(n - 1, k) + try1(n - 1, k - 1);
    return d[n][k];
}

int main(){
    int n, k;
    printf("Nhap n va k: ");
    scanf("%d%d", &n, &k);
    printf("To hop chap %d cua %d la: %lld", k, n, try1(n, k));
    return 0;
}