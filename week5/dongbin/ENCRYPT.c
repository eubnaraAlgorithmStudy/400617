#include<stdio.h>
#include<string.h>

int main(){

	char sentence[101];
	char copy[101];
	int T, test_case;
	int len, j, i;

	scanf("%d", &test_case);

	for (T = 0; T < test_case; T++){
		memset(sentence, '\0', 101); memset(copy, '\0', 101);
		scanf("%s", sentence);
		j = 0; len = 0;
		len = strlen(sentence);
		for (i = 0; i < len; i++){
			if (i % 2 == 0){
				copy[j] = sentence[i]; j++;
			}
			else{ continue; }
		}
		for (i = 0; i < len; i++){
			if (i % 2 != 0){
				copy[j] = sentence[i]; j++;
			}
		}
		printf("%s\n", copy);
	}

	return 0;
}