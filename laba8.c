#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line(char buffer[]);
void main(void)
{
	char line[MAXLINE];
	gets(line);
	process_line(line);
	puts(line);
	system("pause");
}
void process_line(char buffer[])
{
	char c; // текущий символ
	char prev_c; // предыдущий символ
	int flag; // признак слова
	int found; // признак того, что буквы повторились
	int i=0; // позиция текущего символа
	char *mass[100];
	char *start; // позиция начала слова
	char *stop; // позиция конца слова
	char *ptr, *cptr, *cstart;
	char copyLine[MAXLINE];
	int j, k;
	flag = NO;
	found = NO;
	prev_c = ' ';
	start = buffer;
	stop = buffer;
	ptr = buffer;
	cstart = copyLine;
	cptr = copyLine;
	i = 0;
	strcpy(copyLine, buffer);
	do
	{
		c = *cptr; // взять текущий символ из буфера
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
		{
			// найден разделитель
			if (flag == YES)
			{
				// найден первый разделить после слова
				stop = ptr - 1; // запомнить позицию конца слова
				*cptr = '\0';
				for (j = 0; j < i; j++)
				{
					if (!strcmp(cstart, mass[j]))
					{
						found = YES;
					}
				}
				mass[i++] = cstart;
				if (found == YES)
				{
					char *src = stop + 1;
					char *dst = start;
					while ((*dst++ = *src++) != '\0');
					ptr = start;
				}
			}
			found = NO;
			flag = NO;
		}
		else
		{
			if (flag == NO) 
			{
				start = ptr;
				cstart = cptr;
			}
			flag = YES;
		}
		cptr++;
		ptr++;
	} while (c != '\0');
}
