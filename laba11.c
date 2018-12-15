#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define LETTER 1
#define NOT_THE_LETTER 0
#define MAXLEN 1000
#define B 10.2
void main(void)
{
	HANDLE hStdout;
	FILE *fp;
	char line[MAXLEN];
	char word[MAXLEN];
	char mword[MAXLEN];
	char mass[10][50];
	int i, j = 0, k;
	int flag;
	int flag_print = 1;
	int prev_flag;
	int mflag = 0;
	char *ptr;
	char *begin;
	char *start;
	float a = B;
	WORD foregroundColor0;
	WORD textAttribute;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_GREEN;
	fp = fopen("input.txt", "rt");
	if (fp == NULL)
		return;
	while (!feof(fp))
	{
		ptr = fgets(line, MAXLEN, fp);
		if (ptr == NULL)
			break;
		i = 0;
		prev_flag = flag = NOT_THE_LETTER;
		word[0] = '\0';
		while (*ptr != 0)
		{
			prev_flag = flag;
			if (*ptr == ' ' || *ptr == ',' || *ptr == '.' || *ptr == '\n' || *ptr == '(' || *ptr == ')' || *ptr == '!' || *ptr == ';')
				flag = NOT_THE_LETTER;
			else
				flag = LETTER;
			SetConsoleTextAttribute(hStdout, 7);
			if (flag != prev_flag)
			{
				word[i] = '\0';
				if (*ptr == '\n')
				{
					mflag = 0;
					flag_print = 1;
				}
				if (mflag && prev_flag && flag_print)
				{
					strcpy(mword, word);
					strcpy(mass[j], word);
					flag_print = 0;
				}
				if (mflag && *ptr == '.' && !flag_print)
				{
					j++;
					textAttribute = foregroundColor0;
					SetConsoleTextAttribute(hStdout, textAttribute);
					printf("%s ", mword);
					SetConsoleTextAttribute(hStdout, 7);
					flag_print = 1;
					mflag = 0;
				}
				if (!strcmp(word, "#define\0"))
				{
					mflag = 1;
				}
				for (k = 0; k < 10; k++)
				{
					if (!strcmp(word, &mass[k]))
					{
						textAttribute = foregroundColor0;
						SetConsoleTextAttribute(hStdout, textAttribute);
					}
				}
				if (flag_print)
					printf("%s", word);
				i = 0;
			}
			word[i++] = *ptr++;
		}
		if (i != 0)
		{
			word[i] = '\0';
			printf("%s", word);
		}
	}
	printf("\n");
	fclose(fp);
	system("pause");
}
