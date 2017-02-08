// Header files inclusion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declare
void CHANGEURI(char ** uri_save, char * uri, char * uri_result, int key);

int main(void)
{
	// Local variables declare
	char * uri = NULL;
	char * uri_result = NULL;
	int key = 0;
	int i = 0;
	char ** uri_save = NULL; // keyø° ¥Î«— pointer str

	// Statements
	scanf_s("%d", &key);
	uri_save = (char **)malloc(sizeof(char*) * key);
	getchar();

	for (i = 0; i < key; i++)
	{
		uri = (char *)malloc(sizeof(char) * 81);
		uri_result = (char *)malloc(sizeof(char) * 81);
		gets(uri);
		CHANGEURI(uri_save, uri, uri_result, i);
	}
	for (i = 0; i < key; i++)
	{
		printf("%s\n", *(uri_save + i));
	}



	free(uri);
	free(uri_result);
	free(uri_save);
	return 0;
}
// Function definition
void CHANGEURI(char ** uri_save, char * uri, char * uri_result, int key)
{
	// Local variables declare
	int i = 0;
	int j = 0;

	// Statements
	while (*(uri + i) != '\0')
	{
		if (*(uri + i) == '%')
		{
			if (*(uri + (i + 1)) == '2')
			{
				switch (*(uri + (i + 2)))
				{
				case '0':
				{
					*(uri_result + j) = ' ';
					j++;
					i += 3;
					break;
				}
				case '1':
				{
					*(uri_result + j) = '!';
					j++;
					i += 3;
					break;
				}
				case '4':
				{
					*(uri_result + j) = '$';
					j++;
					i += 3;
					break;
				}
				case '5':
				{
					*(uri_result + j) = '%';
					j++;
					i += 3;
					break;
				}
				case '8':
				{
					*(uri_result + j) = '(';
					j++;
					i += 3;
					break;
				}
				case '9':
				{
					*(uri_result + j) = ')';
					j++;
					i += 3;
					break;
				}
				case 'a':
				{
					*(uri_result + j) = '*';
					j++;
					i += 3;
					break;
				}
				default:
				{
					*(uri_result + j++) = *(uri + i++);
					break;
				}
					
				}

			}
		}
		else
		{
			*(uri_result + j++) = *(uri + i++);
		}
	}

	*(uri_result + j) = '\0';
	*(uri_save + key) = uri_result;
}

