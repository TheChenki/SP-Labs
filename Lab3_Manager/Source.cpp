#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <locale.h>
using namespace std;

void change_dir();
void print_dir();
void copy_file();
void create_dir();
void remove_file();
void remove_dir();
void print_file();

int main(void)
{
	setlocale(LC_ALL, "Russian");
	char path[MAX_PATH];
	strcpy(path, "D://");
	while (true) 
	{
		system("cls");
		if (GetCurrentDirectoryA(MAX_PATH, path) != 0)
		{
			printf("Current dir: %s\n", path);
		}
		else
		{
			printf("Произошла ошибка, программа будет закрыта :( \n");
			exit(1);
		}

		printf("1 - Сменить директорию\n");
		printf("2 - Распечатать директорию\n");
		printf("3 - Скопировать файл\n");
		printf("4 - Создать директорию\n");
		printf("5 - Удалить файл\n");
		printf("6 - Удалить директорию\n");
		printf("7 - Информация о файле\n");
		printf(">> ");
		int action;
		scanf_s("%i", &action);
		switch (action)
		{
			case 1: change_dir(); break;
			case 2: print_dir(); break;
			case 3: copy_file(); break;
			case 4: create_dir(); break;
			case 5: remove_file(); break;
			case 6: remove_dir(); break;
			case 7: print_file(); break;
			default: printf("invalid input\n");
		}
	}
}
void change_dir()
{
	printf("Введите путь.\nНапример C://Folder/Name/\n");
	printf(">> ");
	char path[MAX_PATH];
	scanf_s("%s", path, MAX_PATH);
	if (SetCurrentDirectoryA((LPCSTR)path))
	{
		if (GetCurrentDirectoryA(MAX_PATH, path) != 0)
		{
			printf("Директория изменена!\n");
			system("pause");
		}
		else 
		{
			printf("Произошла ошибка, программа будет закрыта :( \n");
			system("pause");
			exit(1);
		}
	}
	else
	{
		printf("Не получилось сменить директорию. Возможно вы ошиблись при вводе :( \n");
		system("pause");
	}
}

void print_dir()
{
	WIN32_FIND_DATAA file;
	HANDLE hf;
	char path[MAX_PATH];

	if (GetCurrentDirectoryA(MAX_PATH, path) != 0)
	{
		system("cls");
		strcat(path, "//*");
		hf = FindFirstFileA(path, &file);
		if (hf == INVALID_HANDLE_VALUE) 
		{
			printf("Произошла ошибка :(\n");
			system("Pause");
			return;
		}
		else {
			do 
			{
				
				if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
					printf("[DIR] ");
				else
					printf("[FILE] ");

				printf("%s\n", file.cFileName);

				SYSTEMTIME time;
				FileTimeToSystemTime(&file.ftCreationTime, &time);
				printf("Создан: %02d-%02d-%d %02d:%02d:%02d", time.wMonth, time.wDay, time.wYear, time.wHour, time.wMinute, time.wSecond);
				printf("Размер: %dB\n", file.nFileSizeLow);
				printf("*********************************\n");

			}
			while (FindNextFileA(hf, &file));
			system("Pause");
			FindClose(hf);
		}
	}
	else
	{
		printf("Произошла ошибка, программа будет закрыта :( \n");
		system("pause");
		exit(1);
	}


}

void copy_file()
{
	char oldPath[MAX_PATH];
	char newPath[MAX_PATH];
	system("cls");
	printf("Введите путь и имя файла.\nНапример C://Folder/image.png\n");
	printf(">>");
	scanf_s("%s", oldPath, MAX_PATH);
	printf("Введите новый путь и имя файла.\nНапример D://Folder/newname.png\n");
	printf(">>");
	scanf_s("%s", newPath, MAX_PATH);
	if (CopyFileA((LPCSTR)oldPath, (LPCSTR)newPath, FALSE)) 
	{
		printf("Файл скопирован!\n");
	}
	else 
	{
		printf("Не получилось скопировать файл :(\n");
	}
	system("Pause");
}

void create_dir()
{
	char path[MAX_PATH];
	system("cls");
	printf("Введите путь создаваемой директории.\nНапример D://ExistingFolder/NewFolder\n");
	printf(">>");
	scanf_s("%s", path, MAX_PATH);
	if (CreateDirectoryA((LPCSTR)path, NULL))
	{
		printf("Директория создана!\n");
	}
	else
	{
		printf("Не получилось создать директорию :(\n");
	}
	system("pause");
}

void remove_file()
{
	char path[MAX_PATH];
	system("cls");
	printf("Введите путь и имя файла.\nНапример C://Folder/image.png\n");
	printf(">>");
	scanf_s("%s", path, MAX_PATH);
	if (DeleteFileA(path))
	{
		printf("Файл удален!\n");
	}
	else 
	{
		printf("Не получилось удалить файл :(\n");
	}
	system("pause");
}

void remove_dir()
{
	char path[MAX_PATH];
	system("cls");
	printf("Введите путь к директории.\nНапример C://Folder\n");
	printf(">>");
	scanf_s("%s", path, MAX_PATH);
	if (RemoveDirectoryA(path))
	{
		printf("Директория удалена!\n");
	}
	else
	{
		printf("Не получилось удалить директорию :(\n");
	}
	system("pause");
}

void print_file()
{
	char path[MAX_PATH];
	system("cls");
	printf("Введите путь и имя файла.\nНапример C://Folder/image.png\n");
	printf(">>");
	scanf_s("%s", path, MAX_PATH);

	BY_HANDLE_FILE_INFORMATION fileInfo;
	SYSTEMTIME time;
	HANDLE file = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL,
								OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (GetFileInformationByHandle(file, &fileInfo)) 
	{
		SYSTEMTIME time;
		FileTimeToSystemTime(&fileInfo.ftCreationTime, &time);
		printf("Размер: %dB\n", fileInfo.nFileSizeLow);
		FileTimeToSystemTime(&(fileInfo.ftCreationTime), &time);
		printf("Создан: %02d-%02d-%d %02d:%02d:%02d\n", time.wMonth, time.wDay, time.wYear, time.wHour, time.wMinute, time.wSecond);
		FileTimeToSystemTime(&(fileInfo.ftLastAccessTime), &time);
		wprintf(L"Последний доступ был: %02d-%02d-%d %02d:%02d:%02d\n",
			time.wMonth, time.wDay, time.wYear,
			time.wHour, time.wMinute, time.wSecond);
		FileTimeToSystemTime(&(fileInfo.ftLastWriteTime), &time);
		wprintf(L"Последняя запись была: %02d-%02d-%d %02d:%02d:%02d\n",
			time.wMonth, time.wDay, time.wYear,
			time.wHour, time.wMinute, time.wSecond);
		wprintf(L"Количество ссылок: %d\n", fileInfo.nNumberOfLinks);
	}
	else
	{
		printf("Не получилось получить подробной информации о файле :( \n");
	}
	system("pause");
	CloseHandle(file);
}