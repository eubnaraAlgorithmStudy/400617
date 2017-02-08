// Header files inclusion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declare
void XHAENEUNG(char ** uri_save, char * input, int key);
void SPLIT(char * input, char * A, char * B, char * C, char * OP);
void CONVERT(char * A, char * B, char * C, char * OP, int * arr);
int CALCULATE(int * arr);

int main(void)
{
	// Local variables declare
	char * input = NULL;
	int key = 0;
	int i = 0;

	char ** expressions = NULL; // keyø° ¥Î«— pointer string

	// Statements
	scanf_s("%d", &key);
	expressions = (char **)malloc(sizeof(char*) * key);
	getchar();
	
	for (i = 0; i < key; i++)
	{
		input = (char *)malloc(sizeof(char) * 30);
		
		gets(input);
		XHAENEUNG(expressions, input, i);
	}
	for (i = 0; i < key; i++)
	{
		printf("%s\n", *(expressions + i));
	}



	free(input);
	free(expressions);
	return 0;
}
// Function definition
int CALCULATE(int * arr)
{
	// Local variables declare
	int result = 0;

	// Statements
	switch (*(arr + 3))
	{
	case 1:
	{
		result = (*(arr + 0)) + (*(arr + 1));
		break;
	}
	case 2:
	{
		result = (*(arr + 0)) - (*(arr + 1));
		break;
	}
	case 3:
	{
		result = (*(arr + 0)) * (*(arr + 1));
		break;
	}
	default:
		break;
	}

	if ((result != *(arr + 2)) || (result > 10) || (result < 0))
		return 1;
	else
		return 2;
}
void CONVERT(char * A, char * B, char * C, char * OP, int * arr)
{
	// Local variables declare
	int i = 0;
	int length_a = 0;
	int total_a = 0;
	int length_b = 0;
	int total_b = 0;
	int length_c = 0;
	int total_c = 0;

	// Statements
	length_a = strlen(A);
	length_b = strlen(B);
	length_c = strlen(C);
	while (*(A + i) != '\0')
	{
		switch (*(A + i))
		{
		case 'e':
		{
			total_a += 1;
			break;
		}
		case 'f':
		{
			total_a += 2;
			break;
		}
		case 'g':
		{
			total_a += 3;
			break;
		}
		case 'h':
		{
			total_a += 4;
			break;
		}
		case 'i':
		{
			total_a += 5;
			break;
		}
		case 'n':
		{
			total_a += 6;
			break;
		}
		case 'o':
		{
			total_a += 7;
			break;
		}
		case 'r':
		{
			total_a += 8;
			break;
		}
		case 's':
		{
			total_a += 9;
			break;
		}
		case 't':
		{
			total_a += 10;
			break;
		}
		case 'u':
		{
			total_a += 11;
			break;
		}
		case 'w':
		{
			total_a += 12;
			break;
		}
		case 'x':
		{
			total_a += 13;
			break;
		}
		case 'z':
		{
			total_a += 14;
			break;
		}
		case 'v':
		{
			total_a += 15;
			break;
		}
		default:
			break;
		}

		i++;
	}
	switch (total_a)
	{
	case 30:
	{
		*(arr + 0) = 0;
		break;
	}
	case 14:
	{
		*(arr + 0) = 1;
		break;
	}
	case 29:
	{
		*(arr + 0) = 2;
		break;
	}
	case 24:
	{
		*(arr + 0) = 3;
		break;
	}
	case 28:
	{
		*(arr + 0) = 4;
		break;
	}
	case 23:
	{
		if(length_a == 4)
			*(arr + 0) = 5;
		else
			*(arr + 0) = 8;
		break;
	}
	case 27:
	{
		*(arr + 0) = 6;
		break;
	}
	case 32:
	{
		*(arr + 0) = 7;
		break;
	}
	case 18:
	{
		*(arr + 0) = 8;
		break;
	}
	case 17:
	{
		*(arr + 0) = 9;
		break;
	}
	default:
		break;
	}

	i = 0;
	while (*(B + i) != '\0')
	{
		switch (*(B + i))
		{
		case 'e':
		{
			total_b += 1;
			break;
		}
		case 'f':
		{
			total_b += 2;
			break;
		}
		case 'g':
		{
			total_b += 3;
			break;
		}
		case 'h':
		{
			total_b += 4;
			break;
		}
		case 'i':
		{
			total_b += 5;
			break;
		}
		case 'n':
		{
			total_b += 6;
			break;
		}
		case 'o':
		{
			total_b += 7;
			break;
		}
		case 'r':
		{
			total_b += 8;
			break;
		}
		case 's':
		{
			total_b += 9;
			break;
		}
		case 't':
		{
			total_b += 10;
			break;
		}
		case 'u':
		{
			total_b += 11;
			break;
		}
		case 'w':
		{
			total_b += 12;
			break;
		}
		case 'x':
		{
			total_b += 13;
			break;
		}
		case 'z':
		{
			total_b += 14;
			break;
		}
		case 'v':
		{
			total_b += 15;
			break;
		}
		default:
			break;
		}

		i++;
	}
	switch (total_b)
	{
	case 30:
	{
		*(arr + 1) = 0;
		break;
	}
	case 14:
	{
		*(arr + 1) = 1;
		break;
	}
	case 29:
	{
		*(arr + 1) = 2;
		break;
	}
	case 24:
	{
		*(arr + 1) = 3;
		break;
	}
	case 28:
	{
		*(arr + 1) = 4;
		break;
	}
	case 23:
	{
		if (length_b == 4)
			*(arr + 1) = 5;
		else
			*(arr + 1) = 8;
		break;
	}
	case 27:
	{
		*(arr + 1) = 6;
		break;
	}
	case 32:
	{
		*(arr + 1) = 7;
		break;
	}
	case 18:
	{
		*(arr + 1) = 8;
		break;
	}
	case 17:
	{
		*(arr + 1) = 9;
		break;
	}
	default:
		break;
	}

	i = 0;
	while (*(C + i) != '\0')
	{
		switch (*(C + i))
		{
		case 'e':
		{
			total_c += 1;
			break;
		}
		case 'f':
		{
			total_c += 2;
			break;
		}
		case 'g':
		{
			total_c += 3;
			break;
		}
		case 'h':
		{
			total_c += 4;
			break;
		}
		case 'i':
		{
			total_c += 5;
			break;
		}
		case 'n':
		{
			total_c += 6;
			break;
		}
		case 'o':
		{
			total_c += 7;
			break;
		}
		case 'r':
		{
			total_c += 8;
			break;
		}
		case 's':
		{
			total_c += 9;
			break;
		}
		case 't':
		{
			total_c += 10;
			break;
		}
		case 'u':
		{
			total_c += 11;
			break;
		}
		case 'w':
		{
			total_c += 12;
			break;
		}
		case 'x':
		{
			total_c += 13;
			break;
		}
		case 'z':
		{
			total_c += 14;
			break;
		}
		case 'v':
		{
			total_c += 15;
			break;
		}
		default:
			break;
		}

		i++;
	}
	switch (total_c)
	{
	case 30:
	{
		*(arr + 2) = 0;
		break;
	}
	case 14:
	{
		*(arr + 2) = 1;
		break;
	}
	case 29:
	{
		*(arr + 2) = 2;
		break;
	}
	case 24:
	{
		*(arr + 2) = 3;
		break;
	}
	case 28:
	{
		*(arr + 2) = 4;
		break;
	}
	case 23:
	{
		if (length_c == 4)
			*(arr + 2) = 5;
		else
			*(arr + 2) = 8;
		break;
	}
	case 27:
	{
		*(arr + 2) = 6;
		break;
	}
	case 32:
	{
		*(arr + 2) = 7;
		break;
	}
	case 18:
	{
		*(arr + 2) = 8;
		break;
	}
	case 17:
	{
		*(arr + 2) = 9;
		break;
	}
	default:
		break;
	}

	i = 0;
	switch (*(OP + i++) != '\0')
	{
	case '+':
	{
		*(arr + 3) = 1;
		break;
	}
	case '-':
	{
		*(arr + 3) = 2;
		break;
	}
	case '*':
	{
		*(arr + 3) = 3;
		break;
	}
	default:
		break;
	}

}
void SPLIT(char * input, char * A, char * B, char * C, char * OP)
{
	// Local variables declare
	int i = 0;
	int j = 0;
	int k = 0;

	// Statements
	while (*(input + i) != ' ')
	{
		*(A + i) = *(input + i);
		i++;
	}
	*(A + i) = '\0';
	
	i++;
	*(OP) = *(input + i);
	*(OP + 1) = '\0';

	i += 2;
	while (*(input + i) != ' ')
	{
		*(B + j++) = *(input + i++);
	}
	*(B + j) = '\0';

	i += 3;
	while (*(input + i) != '\0')
	{
		*(C + k++) = *(input + i++);
	}
	*(C + k) = '\0';
}
void XHAENEUNG(char ** expressions, char * input, int key)
{
	// Local variables declare
	int i = 0;
	int j = 0;
	char * A = NULL;
	char * B = NULL;
	char * C = NULL;
	char * OP = NULL;
	int arr[4] = {0,};
	int trueorfalse = 0;

	// Statements
	A = (char *)malloc(sizeof(char) * 7);
	B = (char *)malloc(sizeof(char) * 7);
	C = (char *)malloc(sizeof(char) * 7);
	OP = (char *)malloc(sizeof(char) * 2);
	//arr = (int *)malloc(sizeof(int) * 4);

	SPLIT(input, A, B, C, OP);
	CONVERT(A, B, C, OP, arr);
	trueorfalse = CALCULATE(arr);

	if(trueorfalse == 2)
		*(expressions + key) = "YES";
	else
		*(expressions + key) = "NO";

	free(A);
	free(B);
	free(C);
	free(OP);
	//free(arr);
}

