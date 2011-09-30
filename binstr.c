#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "binstr.h"

/** 
 * Reads in character (byte) array and returns string 
 * representation of binary 
 * 
 * Note: if strlen() is used for strLen, function will 
 * stop at first 0 ('\0') value
 **/
void str2bs(const char *str, size_t strLen, char *bitStr) {
	while(strLen--) {
		bitStr[0] = (*str & 0x80) ? '1': '0';
		bitStr[1] = (*str & 0x40) ? '1': '0';
		bitStr[2] = (*str & 0x20) ? '1': '0';
		bitStr[3] = (*str & 0x10) ? '1': '0';
		bitStr[4] = (*str & 0x08) ? '1': '0';
		bitStr[5] = (*str & 0x04) ? '1': '0';
		bitStr[6] = (*str & 0x02) ? '1': '0';
		bitStr[7] = (*str & 0x01) ? '1': '0';
	 
		bitStr += 8;
		str++;
	}
	*bitStr = 0;
}

/* Convert binary string to unsigned value */
unsigned long long bs2ui(char *bitStr) {
	unsigned long long val = 0;
	while(*bitStr) {
		val = (val << 1) | (*bitStr & 1);
		bitStr++;
	}

	return val;
}

/* Convert binary string to signed value, with MSB as sign bit */
long long bs2i(char *bitStr) {
	long long val = 0l;

	size_t len = strlen(bitStr);
	char size = CHAR_BIT;
	while(len > size) size <<= 1;

	char msb = *bitStr & 1;
	bitStr++;
	while(*bitStr) {
		val = (val << 1l) | (*bitStr & 1);
		bitStr++;
	}
	val = ((long long)msb << size-1l) | val; /* Use MSB as sign bit */

	return val;
}

/* Convert binary string to float, string must be length 8*sizeof(float) */
float bs2f(char *bitStr) {
	assert(strlen(bitStr) == (8*sizeof(float)));

	float val = 0.0;
	int *ptr = (int *)(&val);
	while (*bitStr) {
		*ptr = (*ptr << 1) | (*bitStr & 1);
		bitStr++;
	}

	return val;
}

/* Convert binary string to double, string must be length 8*sizeof(double) */
double bs2d(char *bitStr) {
	assert(strlen(bitStr) == (8*sizeof(double)));

	double val = 0.0;
	long long *ptr = (long long *)(&val);
	while (*bitStr) {
		*ptr = (*ptr << 1) | (*bitStr & 1);
		bitStr++;
	}

	return val;
}

