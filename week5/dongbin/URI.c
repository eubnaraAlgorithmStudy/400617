#include<stdio.h>
#include<string.h>
char URI[101];
char copy[101];

int func(char c){
	switch (c)
	{
	case '0':
		return 1; break;
	case '1':
		return 1; break;
	case '4':
		return 1; break;
	case '5':
		return 1; break;
	case '8':
		return 1; break;
	case '9':
		return 1; break;
	case 'a':
		return 1; break;
	default:
		return 0; break;
	}
}
char str_match(char c){

	switch (c)
	{
	case '0':
		return ' ';	break;
	case '1':
		return '!';	break;
	case '4':
		return '$';	break;
	case '5':
		return '%'; break;
	case '8':
		return '('; break;
	case '9':
		return ')'; break;
	case 'a':
		return '*'; break;
	default:
		break;
	}
}
void str_change(){

	int len = 0, i, j;
	len = strlen(URI);

	for (i = 0, j = 0; i < len; i++){
		if (URI[i] == '%'){
			if (URI[i + 1] == '2'){
				if (func(URI[i+2])){
					URI[i] = str_match(URI[i + 2]);
					copy[j++] = URI[i]; i += 2;
				}
				else{
					copy[j++] = URI[i];
				}
			}
		}
		else{
			copy[j++] = URI[i];
		}
	}
	printf("%s\n", copy);
	memset(URI, '\0', len); memset(copy, '\0', len);
}
int main(){

	int Test_case, T;		

	scanf("%d", &Test_case);
	for (T = 0; T < Test_case; T++){
		scanf("%s", URI);
		str_change(); 
	}
}