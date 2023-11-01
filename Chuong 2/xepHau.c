#include <stdio.h>

int n, d[100];

void print(){
    for (int i = 1; i <= n; i++)
        printf("%d", d[i]);
    printf("\n");
}

int check(int cnt, int k){
    for (int i = 1; i < cnt; i++) {
        if (d[i] == k) return 0;
        if (cnt + k == i + d[i]) return 0;
        if (cnt - k == i - d[i]) return 0;
    }
    return 1;
}

void try1(int cnt){
    if (cnt == n + 1){
        print(); return;
    }
    for (int i = 1; i <= n; i++){
        if (check(cnt, i)){
            d[cnt] = i;
            try1(cnt + 1);
        }
    }
}

int main(){
    printf("So quan hau can xep: ");
    scanf("%d", &n);
    printf("Cac cach xep n quan hau:\n");
    try1(1);
    return 0;
}