#include <stdio.h>
#include <string.h>

char c[100];

int doiXung(int l, int r){
    if (l >= r) return 1;
    if (c[l] != c[r]) return 0;
    return doiXung(l + 1, r - 1);
}

int main(){
    scanf("%s", &c);
    int n = strlen(c);
    if (doiXung(0, n - 1)) printf("TRUE");
    else printf("FALSE");
    return 0;
}
