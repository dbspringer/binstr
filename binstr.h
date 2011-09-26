#ifndef _BINSTR_H_
#define _BINSTR_H_

/* Substring macro for sub-sampling binary strings */
#ifndef substr
#define substr(dest, src, dest_size, startPos, strLen)	snprintf(dest, dest_size, "%.*s", strLen, src+startPos)
#endif

/* String to binary string conversions */
void 			str2bs(char *str, char *bitStr);

/* Binary string to value conversions */
unsigned char 		bs2uc(char *bitStr);
char 			bs2c(char *bitStr);
unsigned short 		bs2ush(char *bitStr);
short 			bs2sh(char *bitStr);
unsigned int 		bs2ui(char *bitStr);
int 			bs2i(char *bitStr);
unsigned long long 	bs2ul(char *bitStr);
long long 		bs2l(char *bitStr);
float 			bs2f(char *bitStr);
double 			bs2d(char *bitStr);

#endif /* _BINSTR_H_ */

