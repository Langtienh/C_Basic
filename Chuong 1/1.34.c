#include<stdio.h>

typedef struct point {
    double x;
    double y;
} point;

typedef struct circle{
    point cen;
    double rad;
} circle;

int is_in_circle(point p, circle c){
    double x = p.x - c.cen.x;
    double y = p.y - c.cen.y;
    double r = c.rad;
    return x * x + y * y <= r * r;
}

int main(){
    point p;
    circle c;
    printf("Enter point coordinates\n"); scanf("%lf%lf", &p.x, &p.y);
    printf("Enter circle center coordinates\n"); 
    scanf("%lf%lf", &c.cen.x, &c.cen.y);
    printf("Enter circle radius\n"); scanf("%lf", &c.rad);
    if (is_in_circle(p, c))
        printf("point is in circle\n");
    else
        printf("point is out of circle\n");
return 0;
}