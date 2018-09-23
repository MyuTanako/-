#include <stdio.h>
// определение символических констант
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line( char buffer[] );
void main( void )
{
	char line[MAXLINE];
	gets( line );
	process_line( line );
	puts( line );
}

void process_line( char buffer[] )
{
	char *buf_ptr; // указатель на текущий символ буфера
	char *end; // указатель на конец слова
	char *begin; // указатель на начало слова
	char c; // текущий символ
	int flag; // признак слова
	int found; // признак того, что буквы повторились
	// начальные присваивания (инициализация переменных)
	int counter = -1;
	int i, plus;
	char *match[100];
	flag = NO;
	found = NO;
	buf_ptr = buffer;
	begin = buffer;
	end = buffer;
	// цикл чтения символов из строки
	for(i)
	do
	{
		c = *buf_ptr; // взять текущий символ из буфера
		if( c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
		{
			// найден разделитель
			if( flag == YES )
			{
				// найден первый разделить после слова
				end = buf_ptr - 1; // запомнить указатель на
				// конец слова
				while(match[counter] !='\0')
				for(i=0;i<counter-1;i++);
				{
					plus = (strcmp(match[i], match[counter]));
					if (plus == 0)
						found = YES;
					else
					{
						if(match[i+1]<match[i]+plus)
						{
							found = YES;
						}
					}
				}
				if( found == YES )
				{
					// две последних буквы в слове были одинаковы
					// слово нужно удалить
					char *src = end + 1;
					char *dst = begin;
					// удаление слова (перенос оставшейся части
					// строки)
					while( (*dst++ = *src++ ) != '\0' );
					buf_ptr = begin; // начать обработку строки с
					// перенесённого фрагмента
				}
			flag = NO;
			found = NO;
			}
		}
		else
		{
			// найдена буква
			if( flag == NO ){
				begin = buf_ptr; // запомнить указатель на начало
				counter++; // Считаем кол-во слов
				match[counter] = buf_ptr;
			}
			flag = YES;
		}
		buf_ptr++; // продвинуть вперёд указатель на текущий символ
	}
	while( c != '\0' );
}