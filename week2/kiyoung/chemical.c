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
	//¥�������� ���� 2��,1���� �����ֱ���ǥ�� �ִ��� Ȯ��. nal���� ��쿡 na/l�� ¥���� �ȵ�. n/al�� ©�����
	//�� ���� 2��,1���� �ִ� ��쿡�� ©��. ���� 2��,1���� ��츦 Ȯ���ϰ� ������ ¥�� �迭 1���� �ٿ�Ȯ��.
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

	//�׽�Ʈ�� ����迭[2]�� ����� ���� �־��ش�.
	for (int j = 0; j < 2; j++) {
		isfit[j] = a[j]; //a�迭�� �ϳ� ������ �� �޸��� ������ �ɶ�?
		if (a[j] == NULL) //�̰� �ϳ� ���Ҵٴ� �Ҹ�.
		{
			cutIndex = 1;
		}
	}
	for (int i = 0; i < 120; i++)
	{//cutindex�� 1�� ��� : 1. ���2���� ã�Ҵµ� ��� �������� �Ѿ�� ���. 2. ��ǲ�� Ȧ���̰� 2������ ��ġ�ϰ��� 1�����ԵǴ°��
		if (a[0] == NULL)
			return 1;
		//���⼭ ��ҹ��ڹٲ���ߵ�.�빮�ڸ� -> �ҹ��ڷ�. +32.

		//����迭�� ���ұ�ȣ�� ���Ѵ�. 
		if (strcmp(isfit, cheMap[i]) == 0)
		{
			cut(*(&a), cutIndex);
		}
		//�ѹ� �ƴ� ���-> �׽�Ʈ����迭�� ���� blank�� �־ ������ ¥��.
		//������ �ƴѰ��-> return 0.
		else {
			if (i == 119 && flag == 0)
			{
				//�ϳ��� ©�� ��ġ�ؾ���. 
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
//ó������ �� �˻��� �� �ִµ� �״����� ����.heh�� ���ѷ���=> he�������� h���µ� ���⼭ ���ѷ���, hhe�� �ƹ��͵��ȳ���.