// Header files inclusion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declare
void Encrypt(char * string, int key, char ** str);

int main(void)
{
	// Local variables declare
	char * string = NULL;
	int key;
	int i;
	char ** str = NULL;// keyø° ¥Î«— pointer str

	// Statements
	scanf_s("%d", &key);
	str = (char **)malloc(sizeof(char *) * key);
	getchar();

	for (i = 0; i < key; i++)
	{
		string = (char *)malloc(sizeof(char) * 101);
		gets(string);
		Encrypt(string, i, str);
	}
	for (i = 0; i < key; i++)
	{
		printf("%s\n", *(str + i));
	}

	free(string);
	free(str);

	return 0;
}
// Function definition
void Encrypt(char * string, int key, char ** str)
{
	// Local variables declare
	int i = 0;
	int j;
	int len;
	char temp;
	char * temp_string = NULL;
	
	// Statements
	temp_string = (char *)malloc(sizeof(char) * 101);
	len = strlen(string);

	for (j = 0; j < len; j += 2)
	{	// Approach string
		*(temp_string + i++) = *(string + j);
	}
	for (j = 1; j < len; j += 2)
	{
		*(temp_string + i++) = *(string + j);
	}
	*(temp_string + len) = '\0';
	
	*(str + key) = temp_string;
}

