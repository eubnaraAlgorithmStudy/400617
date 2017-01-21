#include<stdio.h>

int main() {
	
	int T,N,i=0,length=0;
	int test_case;
	int count=0;
	char input[5000 + 10];
	int flag = 0;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {

		scanf("%d", &N);
		scanf("%s", input);
		
		length = N-1;
		while (1)
		{
			if (input[i] == input[length] && flag==1)
			{
				i= length + 1;
				length = N - 1;

				if (i == N) {
					count++;
					i = 0;
					flag = 0;
					break;
				}

				count++;


			}

			else {
				length--;
				
				if (i == length)
					break;
				
			}

			flag = 1;
		}

		if (count == 1)
			count = 0;

		printf("Case #%d\n", test_case);
		printf("%d\n", count);

		count = 0;
	}
	return 0;
}