// https://www.codeground.org/practice/practiceProbView.do?probId=9

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int binary_search(char key[], int start, int end);
char e[114][5] = { "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
"Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
"Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
"Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
"Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
"Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
"Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
"No", "Lr" };

int main(void)
{
	int T; // Test case
	char input[50000], tmp[3];
	int i, j, k;

	for (k = 0; k < 114; k++) {
		for (j = 0; j < 5; j++) {
			if (e[k][j] >= 65 && e[k][j] <= 90) e[k][j] = e[k][j] - 'A' + 'a';
		}
		//strcpy(e[k], tolower(e[k]));
		//printf("%s %d", e[k], k);
	}
	for (i = 0; i < 114; i++) {
		//printf("%s", e[i]);
	}
	// sorting
	for (i = 0; i < 114; i++) {
		for (j = i + 1; j < 114; j++) {
			if (strcmp(e[i], e[j]) > 0) {
				char temp[5];
				strcpy(temp, e[i]);
				strcpy(e[i], e[j]);
				strcpy(e[j], temp);
			}
		}
	}

	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%s", input);
		int flag = 0;

		for (j = 0; j < strlen(input); j++) {
			tmp[0] = input[j], tmp[1] = input[j + 1], tmp[2] = '\0';
			//printf("len: %d, tmp: %s\n", strlen(input), tmp);			
			int len2_result = binary_search(tmp, 0, 114);
			tmp[1] = '\0';
			int len1_result = binary_search(tmp, 0, 114);
			//printf("2: %d   1: %d    ", len2_result, len1_result);
			if (len2_result == 1) { 	// 길이 2 matching 후 i+1
				j++;
				//printf("2!!");
			}
			else if (len1_result == 1) {
				//printf("1!!");
			}
			else {
				flag = 1;
				printf("CASE #%d\n", i+1);
				printf("NO\n");
				break;
			}
			// 길이 1 matching
			// 없으면 FALSE and break
		}
		if (flag == 0) {
			printf("CASE #%d\n", i+1);
			printf("YES\n");
		}
	}
	return 0;
}

int binary_search(char key[], int start, int end)
{
	int mid = (start + end) / 2;
	//printf("mid : %d\n", mid);
	//printf("key : %s  ele: %s\n   ", key, e[mid]);

	if (strcmp(key, e[mid]) == 0) return 1;
	if (start >= end) return -1;
	else if (strcmp(key, e[mid]) > 0) {
		return binary_search(key, mid + 1, end);
	}
	else if (strcmp(key, e[mid]) < 0) {
		return binary_search(key, start, mid - 1);
	}
}