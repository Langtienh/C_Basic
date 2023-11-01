#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Loi tham so \nCu phap: %s <Gia tri luy thua> <Sai so>\n", argv[0]);
        return 1;
    }

    double x = atof(argv[1]);
    double result;

    if (argc == 2) {
        result = exp(x); // Tính lũy thừa e^x
        printf("e^%lf = %lf\n", x, result);
    } else {
        double epsilon = atof(argv[2]);
        result = 1.0;
        double term = 1.0;
        int n = 1;

        while (fabs(term) > epsilon) {
            term *= x / n;
            result += term;
            n++;
        }

        printf("e^%lf (+- %lf) = %lf\n", x, epsilon, result);
    }

    return 0;
}
