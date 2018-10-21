#include <stdio.h>
#define MAXLINE 1024
void main( void )
{
	FILE *fpin; // ������� ����
	FILE *fpout; // �������� ����
	char line[MAXLINE]; // ������� ������
	char *ptr;
	char *buf;
	int i, n;
	n = 30; // ������������
	fpin = fopen( "test.txt", "rt" ); // ������� ���� ��� ������
	if( fpin == NULL )
		return; // ������ ��� �������� �����
	fpout = fopen("result.txt", "wt" ); // ������� ���� ��� ������
	if( fpout == NULL )
		return; // ������ ��� �������� �����
	while( !feof( fpin ) )// ���� �� ����� �������� �����
	{
		ptr = fgets( line, MAXLINE, fpin ); // ������ ������
		if( ptr == NULL )
			break; // ���� ��������
		for(i=0;i<n;i++)
		{
			if( *ptr == ' ' || *ptr == '.' || *ptr == ',' )
			{
				buf = ptr;
			}
			ptr++; // ���������� ��������� �� ������
		}
		*buf++ = '\n'; // ������ ������ "����� ������"
		*buf = '\0'; // ������ ������������ ������
		fputs( line, fpout ); // ������ ������
	}
	fclose( fpin ); // ������� ������� ����
	fclose( fpout ); // ������� �������� ����
}