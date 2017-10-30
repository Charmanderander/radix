/* prof0.c  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fun1(int max) {
	int n;
	double sum =0;
	for(n = 0; n < max; n++ ) {
		sum += sqrt(n+10);
	}
	return sum;
}

double fun2(int max) {
	int n;
	double sum =0;
	for(n = 0; n < max; n++ ) {
		sum += 1.0/n;
	}
	return sum;
}

int main(int argc, char *argv []) 
{
	int n;
	for ( n = 0 ; n < 10000; n++ ) {
		fun1(n+1);
	}
	for ( n = 0 ; n < 10000; n++ ) {
		fun2(n+1);
	}
	return 0;
}
