#include <stdio.h>
#define MAXLINE 1024
void main( void )
{
	FILE *fpin; // входной файл
	FILE *fpout; // выходной файл
	char line[MAXLINE]; // текущая строка
	char *ptr;
	char *buf;
	int i, n;
	n = 30; // ограничитель
	fpin = fopen( "test.txt", "rt" ); // открыть файл для чтения
	if( fpin == NULL )
		return; // ошибка при открытии файла
	fpout = fopen("result.txt", "wt" ); // открыть файл для записи
	if( fpout == NULL )
		return; // ошибка при открытии файла
	while( !feof( fpin ) )// цикл до конца входного файла
	{
		ptr = fgets( line, MAXLINE, fpin ); // чтение строки
		if( ptr == NULL )
			break; // файл исчерпан
		for(i=0;i<n;i++)
		{
			if( *ptr == ' ' || *ptr == '.' || *ptr == ',' )
			{
				buf = ptr;
			}
			ptr++; // продвигаем указатель по строке
		}
		*buf++ = '\n'; // ставим символ "конец строки"
		*buf = '\0'; // ставим ограничитель строки
		fputs( line, fpout ); // запись строки
	}
	fclose( fpin ); // закрыть входной файл
	fclose( fpout ); // закрыть выходной файл
}