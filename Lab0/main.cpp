#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() 
{
	printf("Char:\t\tmin: %i\tmax: %i\tsize: %iB\n",CHAR_MIN,CHAR_MAX,sizeof(char));
	printf("Signed Char:\tmin: %i\tmax: %i\tsize: %iB\n", SCHAR_MIN, SCHAR_MAX, sizeof(signed char));
	printf("Unsigned Char:\tmin: %i\t\tmax: %i\tsize: %iB\n\n", 0, UCHAR_MAX, sizeof(unsigned char));

	printf("Bool:\t\tmin: %i\t\tmax: %i\t\tsize: %iB\n\n", false, true, sizeof(bool));

	printf("Short:\t\tmin: %i\tmax: %i\tsize: %iB\n", SHRT_MIN, SHRT_MAX, sizeof(short));
	printf("Unsigned Short:\tmin: %i\t\tmax: %i\tsize: %iB\n\n", 0, USHRT_MAX, sizeof(unsigned short));

	printf("Int:\t\tmin: %i\tmax: %i\t\tsize: %iB\n", INT_MIN, INT_MAX, sizeof(int));
	printf("Unsigned Int:\tmin: %i\t\t\tmax: %u\t\tsize: %iB\n\n", 0, UINT_MAX, sizeof(unsigned int));

	printf("Long:\t\tmin: %li\tmax: %li\t\tsize: %iB\n", LONG_MIN, LONG_MAX, sizeof(long));
	printf("Unsigned Long:\tmin: %lu\t\t\tmax: %lu\t\tsize: %iB\n\n", 0, ULONG_MAX, sizeof(unsigned long));

	printf("Float:\t\tmin: %e\tmax: %e\tsize: %iB\n", FLT_MIN, FLT_MAX, sizeof(float));
	printf("Double:\t\tmin: %e\tmax: %e\tsize: %iB\n", DBL_MIN, DBL_MAX, sizeof(double));
	printf("Long Double:\tmin: %le\tmax: %le\tsize: %iB\n\n", LDBL_MIN, LDBL_MAX, sizeof(long double));

	printf("Long Long:\t\tmin: %lli\tmax: %lli\tsize: %iB\n", LLONG_MIN, LLONG_MAX, sizeof(long long));
	printf("Unsigned Long Long:\tmin: %i\t\t\t\tmax: %llu\tsize: %iB\n\n", 0, ULLONG_MAX, sizeof(unsigned long long));

	return 0;
}
