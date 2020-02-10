#include <stdio.h>
#include <Windows.h>
int main() 
{
	printf("\tSHORT\t\tSIZE: %iB\t\tMIN: %i\t\tMAX: %i\n",		sizeof(SHORT), -32768, 32767);
	printf("\tWORD\t\tSIZE: %iB\t\tMIN: %i\t\t\tMAX: %i\n",		sizeof(WORD), 0, 65535);
	printf("\tINT\t\tSIZE: %iB\t\tMIN: %i\tMAX: %i\n",			sizeof(INT), -2147483647-1, 2147483647);
	printf("\tUINT\t\tSIZE: %iB\t\tMIN: %u\t\t\tMAX: %u\n",		sizeof(UINT), 0, 4294967295);
	printf("\tDWORD\t\tSIZE: %iB\t\tMIN: %u\t\t\tMAX: %u\n",	sizeof(DWORD), 0, 4294967295);
	printf("\tBYTE\t\tSIZE: %iB\t\tMIN: %i\t\t\tMAX: %i\n",		sizeof(BYTE), 0, 255);
	printf("\tDOUBLE\t\tSIZE: %iB\t\tMIN: %e\tMAX: %e\n",		sizeof(DOUBLE), 1.7E-308, 1.7E+308);
	printf("\tFLOAT\t\tSIZE: %iB\t\tMIN: %e\tMAX: %e\n",		sizeof(FLOAT), 3.4E-38, 3.4E+38);
	printf("\tBOOL\t\tSIZE: %iB\t\tMIN: %i\t\t\tMAX: %i\n",		sizeof(BOOL), FALSE, TRUE);
	printf("\tBOOLEAN\t\tSIZE: %iB\t\tMIN: %i\t\t\tMAX: %i\n",	sizeof(BOOLEAN), FALSE, TRUE);
	printf("\tCHAR\t\tSIZE: %iB\t\tMIN: %i\t\tMAX: %i\n",		sizeof(CHAR), -128, 127);
	printf("\tWCHAR\t\tSIZE: %iB\t\tMIN: %i\t\t\tMAX: %i\n",	sizeof(WCHAR), 0, 65535);
	printf("\tTCHAR\t\tSIZE: %iB\t\tMIN: %i\t\t\tMAX: %i\n",	sizeof(TCHAR), 0, 65535);
	printf("\tLPSTR\t\tSIZE: %iB\t\tMIN: %u\t\t\tMAX: %u\n",	sizeof(LPSTR), 0, 4294967295);
	printf("\tLPCSTR\t\tSIZE: %iB\t\tMIN: %u\t\t\tMAX: %u\n",	sizeof(LPCSTR), 0, 4294967295);
	printf("\tLPWSTR\t\tSIZE: %iB\t\tMIN: %u\t\t\tMAX: %u\n",	sizeof(LPWSTR), 0, 4294967295);
	printf("\tLPCWSTR\t\tSIZE: %iB\t\tMIN: %u\t\t\tMAX: %u\n",	sizeof(LPCWSTR), 0, 4294967295);
	printf("\tLPTSTR\t\tSIZE: %iB\t\tMIN: %u\t\t\tMAX: %u\n",	sizeof(LPTSTR), 0, 4294967295);
	printf("\tLPCTSTR\t\tSIZE: %iB\t\tMIN: %u\t\t\tMAX: %u\n",	sizeof(LPCTSTR), 0, 4294967295);
	system("pause");
	return 0;
}
