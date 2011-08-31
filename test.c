#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "binstr.h"

#define EPSILON 0.0001

int main() {
	char *iStr = "11111111111111111111111100111000";
	int bInt = bs2i(iStr);
	printf("Assert %s == -200\n", iStr, bInt);
	assert(bInt==-200);

	char *fStr = "11000001010001001100110011001101";
	float bFloat = bs2f(fStr);
	printf("%f\n", bFloat);
	assert(fabs(bFloat - -12.3) < EPSILON);

	char *dStr = "0100000000101000100110011001100110011001100110011001100110011010";
	double bDouble = bs2d(dStr);
	printf("%f\n", bDouble);
	assert(fabs(bDouble - 12.3) < EPSILON);

	return 0;
}

