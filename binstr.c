#include <stdio.h>
#include <string.h>
#include "binstr.h"

int bs2i(char *bitStr) {
	if(strlen(bitStr) > 32) return;

	int val = 0;
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 0; i--) {
		if(bitStr[i] == '1') {
			val = 1 << toShift | val;
		}
		
		toShift++;
	}

	return val;
}

float bs2f(char *bitStr) {
	if(strlen(bitStr) != 32) return;

	float val = 0.0;
	int *ptr = (int *)(&val);
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 0; i--) {
		if(bitStr[i] == '1') {
			*ptr = 1 << toShift | *ptr;
		}
		
		toShift++;
	}

	return val;
}

double bs2d(char *bitStr) {
	if(strlen(bitStr) != 64) return;

	double val = 0.0;
	long long *ptr = (long long *)(&val);
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 0; i--) {
		if(bitStr[i] == '1') {
			*ptr = 1ll << toShift | *ptr;
		}
		
		toShift++;
	}

	return val;
}

