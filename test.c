#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "binstr.h"

#define EPSILON 0.00001

int main(void) {
	char *str = "Hello, world!";
	char strBits[8192] = "";
	str2bs(str, 13, strBits);
	printf("%d\t%s\n", strlen(strBits), strBits);

	char *cStr = "10000000";
	unsigned char bUChar = bs2ui(cStr);
	assert(bUChar == 128);
	printf("%s == %d\n", cStr, bUChar);

	char bChar = bs2i(cStr);
	assert(bChar == -128);
	printf("%s == %d\n", cStr, bChar);

	char *sStr = "1111111100111000";
	unsigned short bUShort = bs2ui(sStr);
	assert(bUShort == 65336);
	printf("%s == %d\n", sStr, bUShort);
	
	short bShort = bs2i(sStr);
	assert(bShort == -200);
	printf("%s == %d\n", sStr, bShort);

	char *iStr = "11111111111111111111111100111000";
	unsigned int bUInt = bs2ui(iStr);
	assert(bUInt == 4294967096);
	printf("%s == %u\n", iStr, bUInt);

	int bInt = bs2i(iStr);
	assert(bInt == -200);
	printf("%s == %d\n", iStr, bInt);

	char *lStr = "11111111111101111111111111111111111111111111111111111111111111";
	unsigned long long bULong = bs2ui(lStr);
	printf("%llu\n", bULong);

	long long bLong = bs2i(lStr);
	printf("%lli\n", bLong);

	char *fStr = "11000001010001001100110011001101";
	float bFloat = bs2f(fStr);
	printf("%f\n", bFloat);
	assert(fabs(bFloat - -12.3) < EPSILON);

	char *dStr = "0100000000101000100110011001100110011001100110011001100110011010";
	double bDouble = bs2d(dStr);
	printf("%f\n", bDouble);
	assert(fabs(bDouble - 12.3) < EPSILON);

	char *failStr = "100000000101000100110011001100110011001100110011001100110011010";
	double fDouble = bs2d(failStr);

	return 0;
}

