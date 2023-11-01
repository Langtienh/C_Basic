#include<stdio.h>

int main(int argc, char *argv[]){
	int n = argc;
	while(n--)	printf("%s ", argv[n]);
	return 0;
} 