#include <stdio.h>
#include <string.h>

char c[100];

void reserveStr(int l, int r){
    if (l >= r) return;
    char temp = c[l];
    c[l] = c[r];
    c[r] = temp;
    reserveStr(l + 1, r - 1);
}

int main(){
    scanf("%s", &c);
    int n = strlen(c);
    reserveStr(0, n - 1);
    printf("%s", c);
    return 0;
}
