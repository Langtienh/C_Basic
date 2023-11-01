#include <stdio.h>

int cnt = 0;

void move(int n, char source, char target, char auxiliary1, char auxiliary2) {
    if (n == 1) {
        cnt++;
        printf("B%d: Move disk 1 from %c to %c\n", cnt, source, target);
    } else if (n > 1) {
        move(n - 2, source, auxiliary1, auxiliary2, target);
        move(1, source, auxiliary2, auxiliary1, target);
        move(n - 2, auxiliary1, target, auxiliary2, source);
    }
}

int main() {
    int n;
    printf("Enter the height of the tower: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        move(n, 'A', 'B', 'C', 'D');
    } else {
        move(n, 'A', 'C', 'B', 'D');
    }

    return 0;
}
