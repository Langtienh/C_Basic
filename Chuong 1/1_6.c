#include<stdio.h>

void splip(float num, int *int_part, float *frac_part){
	*int_part = (int)num;
	*frac_part = num - *int_part;
}

int main(){
	float num, frac_part;
	int interger;
	printf("Please enter a real number: \n");
	scanf("%f", &num);
	splip(num, &interger, &frac_part);
	printf("Phan Nguyen: %d\n", interger);
	printf("Phan Thap Phan: %f\n", frac_part);
	return 1;
}