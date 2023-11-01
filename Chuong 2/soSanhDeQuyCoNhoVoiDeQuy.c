#include <stdio.h>

#define ll long long

ll d[1000][1000];

int cnt1, cnt2;

ll try1(int n, int k){
    cnt1++;
    if (k == 0 || k == n) d[n][k] = 1;
    if (d[n][k]) return d[n][k];
    d[n][k] = try1(n - 1, k) + try1(n - 1, k - 1);
    return d[n][k];
}

ll try2(int n, int k){
    cnt2++;
    if (k == 0 || k == n) return 1;
    return try2(n - 1, k) + try2(n - 1, k - 1);
}

int main(){
    int n, k;
    printf("Nhap n va k: ");
    scanf("%d%d", &n, &k);
    printf("To hop chap %d cua %d la: %lld\n", k, n, try1(n, k));
    printf("To hop chap %d cua %d la: %lld\n", k, n, try2(n, k));
    printf("So lan lap cua de quy co nho: %d\n", cnt1);
    printf("So lan lap cua de quy: %d\n", cnt2);
    return 0;
}