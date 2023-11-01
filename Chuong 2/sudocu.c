#include <stdio.h>
#include <string.h>

int d[10][10], ok;

int check(int v, int x, int y){
    for (int i = 0; i < 9; i++)
        if (d[i][x] == v || d[y][i] == v) return 0;
    x /= 3; y /= 3;
    for (int i = y * 3; i < y * 3 + 3; i++)
        for (int j = x * 3; j < x * 3 + 3; j++)
            if (d[i][j] == v) return 0;
    return 1;
}

void print(){
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) 
            printf("%d ", d[i][j]);
        printf("\n");
    }
}

void try1(int x, int y){
    for (int v = 1; v <= 9; v++){
        if (check(v, x, y)){
            d[y][x] = v;
            if (x == 8 && y == 8){
                ok = 1; 
                print(); 
                return;
            }
            if (y == 8) try1(x + 1, 0);
            else try1(x, y + 1);
            d[y][x] = 0;
        }
        if (ok) return;
    }
}

int main(){
    memset(d, 0, sizeof(d));
    try1(0, 0);
    return 0;
}
