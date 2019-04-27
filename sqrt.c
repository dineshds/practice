/*
 ============================================================================
 Name        : sqrt.c
 Author      : Dinesh Deva
 Version     :
 Copyright   : Dinesh Deva
 Description : Naive Program to find Square Root
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAYMAX 1000

int sqrtFloor(int num){
  if(num <= 0) return 0;
  int i=1;
  while(i<=num){
	if((i+1)*(i+1) == num) return i+1;
    if((i+1)*(i+1) > num) break;
    i++;
  }
  return i;
}

double multPrec(int prec){
	return pow((0.1), prec);
}

double increasePrecision(double num, double sq, int currentPrec){

	double mult = multPrec(currentPrec+1);
	double candidate = sq;
	for(int i=1; i<10; i++){
		candidate+=(mult*i);
		if(candidate*candidate > num) break;
	}
	return candidate;
}

double sqrt(double num){
	double sqfl = sqrtFloor(num);

	for(int i=0; i<=5; i++){
		sqfl = increasePrecision(num, sqfl, i);
	}
	return sqfl;
}





int main(void) {
	printf("sqrt of 1 is %f\n", sqrt(1));
	printf("sqrt of 2 is %f\n", sqrt(2));
	printf("sqrt of 3 is %f\n", sqrt(3));
	printf("sqrt of 4 is %f\n", sqrt(4));
	printf("sqrt of 8 is %f\n", sqrt(8));
	return EXIT_SUCCESS;
}
