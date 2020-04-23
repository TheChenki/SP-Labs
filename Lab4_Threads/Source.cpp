
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define ARRAY_MAX 10

CRITICAL_SECTION criticalSection;
HANDLE* threads;
int tlsIndex;

void start(int count);
DWORD WINAPI thread_function(LPVOID arr);
void process_array(int* mainArr, int* resultArr);
int find_largest_divisor(int num);
int sum_elements(int* arr);
void print_array(int* arr);

int main()
{
	int count;

	printf("Input count of threads\n");
	printf(">> ");
	scanf("%i", &count);

	threads = new HANDLE[count];
	srand(time(0));
	InitializeCriticalSection(&criticalSection);
	start(count);
	WaitForMultipleObjects(count, threads, TRUE, INFINITE);
	DeleteCriticalSection(&criticalSection);
	return 0;
}

void start(int count)
{
	InitializeCriticalSection(&criticalSection);
	int** arrays = new int*[count];
	tlsIndex = TlsAlloc();

	for (int i = 0; i < count; i++)
	{
		arrays[i] = new int[ARRAY_MAX];
		for (int j = 0; j < ARRAY_MAX; j++)
			arrays[i][j] = rand() % 90 + 10;

		threads[i] = CreateThread(NULL, 0, thread_function, arrays[i], NULL, NULL);
	}
}

DWORD WINAPI thread_function(LPVOID param)
{
	EnterCriticalSection(&criticalSection);
	printf("I'm Thread! My ID is: %u\n", GetCurrentThreadId());

	int* array = (int*)param;
	TlsSetValue(tlsIndex, (LPVOID)(new int[ARRAY_MAX]));
	int sum = 0;

	printf("My array: ");
	print_array(array);

	process_array(array, (int*)TlsGetValue(tlsIndex));

	printf("\nI'm processed array into: ");
	print_array((int*)TlsGetValue(tlsIndex));

	sum = sum_elements((int*)TlsGetValue(tlsIndex));
	printf("\nSum of processed array: %d\n\n", sum);

	LeaveCriticalSection(&criticalSection);
	return 0;
}

void process_array(int* mainArr, int* resultArr)
{
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		resultArr[i] = find_largest_divisor(mainArr[i]);
	}
}

int find_largest_divisor(int num)
{
	int j = num / 2;
	for (int i = j; i >= 2; i--)
	{
		if (num % i == 0)
			return i;
	}
}

int sum_elements(int* arr)
{
	int result = 0;

	for (int i = 0; i < ARRAY_MAX; i++)
	{
		result += arr[i];
	}

	return result;
}

void print_array(int* arr)
{
	for (int i = 0; i < ARRAY_MAX; i++) {
		printf("%i ", arr[i]);
	}
}






