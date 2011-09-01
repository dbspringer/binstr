#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "binstr.h"

unsigned char bs2uc(char *bitStr) {
	assert(strlen(bitStr) <= 8);

	unsigned char val = 0;
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

char bs2c(char *bitStr) {
	assert(strlen(bitStr) <= 8);

	char val = 0;
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

unsigned short bs2ush(char *bitStr) {
	assert(strlen(bitStr) <= 16);

	unsigned short val = 0;
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

short bs2sh(char *bitStr) {
	assert(strlen(bitStr) <= 16);

	short val = 0;
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

unsigned int bs2ui(char *bitStr) {
	assert(strlen(bitStr) <= 32);

	unsigned int val = 0;
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

int bs2i(char *bitStr) {
	assert(strlen(bitStr) <= 32);

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

unsigned long long bs2ul(char *bitStr) {
	assert(strlen(bitStr) <= 64);

	unsigned long long val = 0;
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 0; i--) {
		if(bitStr[i] == '1') {
			val = 1ll << toShift | val;
		}
		
		toShift++;
	}

	return val;
}

long long bs2l(char *bitStr) {
	assert(strlen(bitStr) <= 64);

	long long val = 0;
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 0; i--) {
		if(bitStr[i] == '1') {
			val = 1ll << toShift | val;
		}
		
		toShift++;
	}

	return val;
}

float bs2f(char *bitStr) {
	assert(strlen(bitStr) == 32);

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
	assert(strlen(bitStr) == 64);

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

