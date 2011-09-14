#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "binstr.h"

void str2bs(char *str, char *bitStr) {
	int i;
	for(i = 0; i < strlen(str); i++) {
		char buffer[9] = "";
		sprintf(buffer, 
			"%c%c%c%c%c%c%c%c", 
			(str[i] & 0x80) ? '1':'0', 
			(str[i] & 0x40) ? '1':'0', 
			(str[i] & 0x20) ? '1':'0', 
			(str[i] & 0x10) ? '1':'0', 
			(str[i] & 0x08) ? '1':'0', 
			(str[i] & 0x04) ? '1':'0', 
			(str[i] & 0x02) ? '1':'0', 
			(str[i] & 0x01) ? '1':'0');
		strncat(bitStr, buffer, 8);
	}
}

unsigned char bs2uc(char *bitStr) {
	assert(strlen(bitStr) <= (8*sizeof(char)));

	unsigned char val = 0;
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 0; i--) {
		if(bitStr[i] == '1') {
			val = (1 << toShift) | val;
		}
		
		toShift++;
	}

	return val;
}

char bs2c(char *bitStr) {
	assert(strlen(bitStr) <= (8*sizeof(char)));

	char val = 0;
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 1; i--) {
		if(bitStr[i] == '1') {
			val = (1 << toShift) | val;
		}
		
		toShift++;
	}
	val = (bitStr[0] << (8*sizeof(char)-1)) | val; /* Use MSB as sign bit */

	return val;
}

unsigned short bs2ush(char *bitStr) {
	assert(strlen(bitStr) <= (8*sizeof(short)));

	unsigned short val = 0;
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 0; i--) {
		if(bitStr[i] == '1') {
			val = (1 << toShift) | val;
		}
		
		toShift++;
	}

	return val;
}

short bs2sh(char *bitStr) {
	assert(strlen(bitStr) <= (8*sizeof(short)));

	short val = 0;
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 1; i--) {
		if(bitStr[i] == '1') {
			val = (1 << toShift) | val;
		}
		
		toShift++;
	}
	val = (bitStr[0] << (8*sizeof(short)-1)) | val; /* Use MSB as sign bit */

	return val;
}

unsigned int bs2ui(char *bitStr) {
	assert(strlen(bitStr) <= (8*sizeof(int)));

	unsigned int val = 0;
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 0; i--) {
		if(bitStr[i] == '1') {
			val = (1 << toShift) | val;
		}
		
		toShift++;
	}

	return val;
}

int bs2i(char *bitStr) {
	assert(strlen(bitStr) <= (8*sizeof(int)));

	int val = 0;
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 1; i--) {
		if(bitStr[i] == '1') {
			val = (1 << toShift) | val;
		}
		
		toShift++;
	}
	val = (bitStr[0] << (8*sizeof(int)-1)) | val; /* Use MSB as sign bit */

	return val;
}

unsigned long long bs2ul(char *bitStr) {
	assert(strlen(bitStr) <= (8*sizeof(long long)));

	unsigned long long val = 0;
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 0; i--) {
		if(bitStr[i] == '1') {
			val = (1ll << toShift) | val;
		}
		
		toShift++;
	}

	return val;
}

long long bs2l(char *bitStr) {
	assert(strlen(bitStr) <= (8*sizeof(long long)));

	long long val = 0;
	int toShift = 0;

	int i;
	for(i = strlen(bitStr)-1; i >= 1; i--) {
		if(bitStr[i] == '1') {
			val = (1ll << toShift) | val;
		}
		
		toShift++;
	}
	val = ((long long)bitStr[0] << (8*sizeof(long long)-1)) | val; /* Use MSB as sign bit */

	return val;
}

float bs2f(char *bitStr) {
	assert(strlen(bitStr) == (8*sizeof(float)));

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
	assert(strlen(bitStr) == (8*sizeof(double)));

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

