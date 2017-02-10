#include<stdio.h>
#include<string.h>

char operation[101];
char A[10]; char B[10];
char C[10]; char operator;

int char_to_int(char arr[]){

	int i, len, result = 0;
	len = strlen(arr);
	if (arr[0] == 'n'){
		return 9;
	}
	for (i = 0; i < len; i++){
		result += arr[i];
	}
	if (result == 448){	return 0; }
	if (result == 322){ return 1; }
	if (result == 346){ return 2; }
	if (result == 536){ return 3; }
	if (result == 444){ return 4; }
	if (result == 426){ return 5; }
	if (result == 340){ return 6; }
	if (result == 545){ return 7; }
	if (result == 529){ return 8; }
	if (result == 327){ return 10; }
}

int calculation(int a, int b){

	int result = 0;
	if (operator == '+'){
		result = a + b;
	}
	else if (operator == '-'){
		result = a - b;
	}
	else if (operator == '*'){
		result = a * b;
	}
	else if (operator == '/'){
		result = a / b;
	}
}

int yes_or_no(int result, int c){
	if (result < 0 || result > 10){
		return 0;
	}
	else{
		if (result == c){
			return 1;
		}
		else{
			return 0;
		}
	}
}
void divide_number(int len){
	
	int i, j, idx = 0;
	int a, b, c;
	
	for (i = 0; i < len; i++){
		if (operation[i] < 97 || operation[i] > 122){
			operator = operation[i]; i++; break;
		}
		A[i] = operation[i];
	}
	
	for (j = 0; i < len;i++){
		if (operation[i] == '='){
			idx = i + 1; break;
		}
		B[j] = operation[i]; j++;
	}
	for (i = 0, j = idx; j < len; i++, j++){
		C[i] = operation[j];
	}

	a = char_to_int(A);
	b = char_to_int(B); 
	c = char_to_int(C);
	
	if (yes_or_no(calculation(a, b), c)){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
}

int main(){

	int T, test_case;
	int len = 0;

	scanf("%d", &test_case);

	for (T = 0; T < test_case; T++){
		memset(operation, '\0', 101); memset(C, '\0', 10);
		memset(A, '\0', 10); memset(B, '\0', 10); operator = '\0';
		scanf("%s", operation);
		len = strlen(operation);
		divide_number(len);
	}
	return 0;
}