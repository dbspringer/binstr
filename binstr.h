#ifndef _BINSTR_H_
#define _BINSTR_H_

/* Substring macro for sub-sampling binary strings */
#ifndef substr
#define substr(dest, src, dest_size, startPos, strLen)	snprintf(dest, dest_size, "%.*s", strLen, src+startPos)
#endif

/* String to binary string conversions */
void 			str2bs(const char *str, size_t strLen, char *bitStr);

/* Binary string to value conversions */
unsigned long long 	bs2ui(char *bitStr);
long long 		bs2i(char *bitStr);
float 			bs2f(char *bitStr);
double 			bs2d(char *bitStr);

#endif /* _BINSTR_H_ */

