#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <locale.h>
void PrintSystemInfo();
void PrintError();

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	if (argc == 2) {
		if (strcmp(argv[1],"-e") == 0) {
			PrintError();
		}
		else if(strcmp(argv[1], "-s") == 0){
			PrintSystemInfo();
		}
		else {
			printf("Invalid argument!");
		}
	}
	else {
		printf("Invalid arguments count!");
	}
	return 0;
}

void PrintError() {
	MEMORYSTATUS status;
	GlobalMemoryStatus(&status);

	HLOCAL memory = LocalAlloc(LPTR, status.dwTotalVirtual*2);
	if (memory == NULL) {
		LPVOID message;
		DWORD code = GetLastError();

		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL,
			code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&message, 0, NULL);

		wprintf(L"Error code: 0x%x\n", code);
		wprintf(L"Error message: %s\n", (char*)message);
	}
	else {
		LocalFree(memory);
	}
}

void PrintSystemInfo() {
	SYSTEM_INFO info;
	GetSystemInfo(&info);

	printf("  Number of processors: %u\n", info.dwNumberOfProcessors);
	printf("  Processor architectire: %u\n", info.wProcessorArchitecture);
	printf("  Processor level: %u\n", info.wProcessorLevel);
	printf("  Processor revision: %u\n", info.wProcessorRevision);
	printf("  Active processor mask: %u\n", info.dwActiveProcessorMask);
	printf("  Page size: %u\n", info.dwPageSize);
	printf("  Minimum application address: %lx\n", info.lpMinimumApplicationAddress);
	printf("  Maximum application address: %lx\n", info.lpMaximumApplicationAddress);
}