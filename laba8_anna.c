#include <stdio.h>
// ����������� ������������� ��������
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
	char *buf_ptr; // ��������� �� ������� ������ ������
	char *end; // ��������� �� ����� �����
	char *begin; // ��������� �� ������ �����
	char c; // ������� ������
	int flag; // ������� �����
	int found; // ������� ����, ��� ����� �����������
	// ��������� ������������ (������������� ����������)
	int counter = -1;
	int i, plus;
	char *match[100];
	flag = NO;
	found = NO;
	buf_ptr = buffer;
	begin = buffer;
	end = buffer;
	// ���� ������ �������� �� ������
	for(i)
	do
	{
		c = *buf_ptr; // ����� ������� ������ �� ������
		if( c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
		{
			// ������ �����������
			if( flag == YES )
			{
				// ������ ������ ��������� ����� �����
				end = buf_ptr - 1; // ��������� ��������� ��
				// ����� �����
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
					// ��� ��������� ����� � ����� ���� ���������
					// ����� ����� �������
					char *src = end + 1;
					char *dst = begin;
					// �������� ����� (������� ���������� �����
					// ������)
					while( (*dst++ = *src++ ) != '\0' );
					buf_ptr = begin; // ������ ��������� ������ �
					// ������������ ���������
				}
			flag = NO;
			found = NO;
			}
		}
		else
		{
			// ������� �����
			if( flag == NO ){
				begin = buf_ptr; // ��������� ��������� �� ������
				counter++; // ������� ���-�� ����
				match[counter] = buf_ptr;
			}
			flag = YES;
		}
		buf_ptr++; // ���������� ����� ��������� �� ������� ������
	}
	while( c != '\0' );
}