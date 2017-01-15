#include<stdio.h>
#include<string.h>

void cut(char *a, int cutIndex);
int search(char *a);
void setToLower();

char cheMap[130][3] = { "H",  "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
"Na", "Mg", "Al","Si", "P", "S", "Cl", "Ar", "K", "Ca",
"Sc", "Ti", "V", "Cr", "Mn", "Fe","Co", "Ni", "Cu", "Zn",
"Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr","Y","Zr",
"Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
"Sb", "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re",
"Os", "Ir", "Pt", "Au","Hg", "Tl", "Pb", "Bi", "Po", "At",
"Rn", "Fr", "Ra", "Rf", "Db", "Sg","Bh", "Hs", "Mt", "Ds",
"Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd","Pm", "Sm",
"Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es",
"Fm", "Md","No", "Lr" };

int sol;
int y = 0, a_length = 0;
char isfit[2] = { 0,0 };
char isfit1[2] = { 0,0 };
char isfit2[1] = { 0 };
char chkfit[2] = { 0,0 };
int flag = 0;
int cutIndex = 2;

int main() {

	char a[50000 + 10];
	int T;
	y = 0, a_length = 0;

	scanf("%d", &T);
	setToLower();
	for (int K = 1; K <= T; K++)
	{

		scanf("%s", &a);
		while (a[y] != NULL)
		{
			y++;
			a_length++;
		}
		sol = search(a);
		if (sol == 1)
			printf("YES\n");
		else
			printf("NO\n");

		cutIndex = 2;
		flag = 0;
	}
}
void setToLower() {
	for (int chg = 0; chg < 120; chg++) {
		cheMap[chg][0] += 32;
	}
}
void cut(char *a, int cutIndex) {
	flag = 0;
	//짜르기전에 다음 2개,1개가 원소주기율표에 있는지 확인. nal같은 경우에 na/l로 짜르면 안돼. n/al로 짤라야해
	//즉 다음 2개,1개가 있는 경우에만 짤라. 다음 2개,1개의 경우를 확인하고 없으면 짜를 배열 1개로 줄여확인.
	for (int z = 0; z < a_length; z++)
	{
			///
			isfit1[0] = a[2];
			isfit1[1] = a[3];

			isfit2[0] = isfit1[0];

			for (int p = 0; p < 120; p++) {
				if ((strcmp(isfit1, cheMap[p]) == 0) || (strcmp(isfit2, cheMap[p]) == 0)) {
					p = 120;
				}
				else {
					z = a_length;
				}
			}
			///

			if (a[0] == NULL)
				break;


			a[z] = a[z + cutIndex];
		}
		search(*(&a));
	}

int search(char *a) {
	cutIndex = 2;
	if (a[0] == 0)
		return 1;

	//테스트할 전용배열[2]을 만들고 값을 넣어준다.
	for (int j = 0; j < 2; j++) {
		isfit[j] = a[j]; //a배열이 하나 남았을 때 메모리의 문제가 될라나?
		if (a[j] == NULL) //이건 하나 남았다는 소리.
		{
			cutIndex = 1;
		}
	}
	for (int i = 0; i < 120; i++)
	{//cutindex가 1인 경우 : 1. 모든2개를 찾았는데 없어서 다음으로 넘어가는 경우. 2. 인풋이 홀수이고 2개에서 서치하고나서 1개남게되는경우
		if (a[0] == NULL)
			return 1;
		//여기서 대소문자바꿔줘야돼.대문자를 -> 소문자로. +32.

		//전용배열과 원소기호를 비교한다. 
		if (strcmp(isfit, cheMap[i]) == 0)
		{
			cut(*(&a), cutIndex);
		}
		//한번 아닌 경우-> 테스트전용배열의 끝에 blank를 넣어서 강제로 짜름.
		//끝까지 아닌경우-> return 0.
		else {
			if (i == 119 && flag == 0)
			{
				//하나로 짤라서 서치해야지. 
				isfit[1] = NULL;
				i = -1;
				flag = 1;
				cutIndex = 1;
			}
			else {
				if (i == 119 && flag == 1)
					return 0;

				continue;
			}
		}
	}
}
//처음에는 다 검색할 수 있는데 그다음이 문제.heh는 무한루프=> he없어지고 h남는데 여기서 무한루프, hhe는 아무것도안나옴.