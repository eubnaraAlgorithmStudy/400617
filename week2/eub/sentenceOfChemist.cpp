#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;
// 1줄에 10개씩 정렬, 26개 알파벳, 인덱스는 1부터시작
enum { _a=1, _b, _c, _d, _e, _f, _g, _h, _i, _j, 
		_k, _l, _m, _n, _o, _p, _q, _r, _s, _t, 
		_u, _v, _w, _x, _y, _z};


const char* chem[114] = {
	"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
	"Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
	"Sc", "Ti", "V", "Cr", "Mn", "Fe","Co", "Ni", "Cu", "Zn",
	"Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y","Zr",
	"Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
	"Sb", "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re",
	"Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At",
	"Rn", "Fr", "Ra", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
	"Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd", "Pm", "Sm",
	"Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
	"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es",
	"Fm", "Md", "No", "Lr"
};

bool isAlphaValid[26+1][26+1];

void setAlpha() {
	int upperOffset = 64;
	int lowerOffset = 96;
	for(int i=0; i<114; i++) {
		if(strlen(chem[i]) == 1) {
			isAlphaValid[chem[i][0] - upperOffset][0] = true;
		} else {
			isAlphaValid[chem[i][0] - upperOffset][chem[i][1] - lowerOffset] = true;
		}
	}
}

//TODO: new 연산을 없애기 위해 2차원 배열로 모두 변경하는 작업
int startIdx = 'a' - 1;
bool canMakeSentence(char* s, int len);

int main(void) {
	// index는 1부터 시작
	int T;
	char input[50005];
	scanf("%d",&T);
	memset(isAlphaValid, false, 27*27*sizeof(bool));
	setAlpha();
	for(int i=1; i<=T; i++) {
		scanf("%s",input);
		printf("Case #%d\n", i);
		if(canMakeSentence(input, strlen(input))) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}

	}
	return 0;
}

//입력은 소문자만 들어온다.
bool canMakeSentence(char* s, int len) {
	bool ret = false;
	queue<int> idxQ;
	bool* isVisited = new bool[len + 1]; 	//같은 곳을 두 번 방문할 필요는 없다. 문자열을 완성할 수 있느냐만 문제지 어떻게 완성하느냐는 중요하지 않기 때문 
	memset(isVisited, 0, sizeof(bool)*(len+1));

	// 첫 위치를 queue에 넣고 시작, 문자열기준이므로 0부터 시작하도록함 코드에서 조금 헷갈리는데 isAlphaValid에 접근할 때의 index는 1부터, 문자열은 0부터 따진다.
	idxQ.push(0);
	while(!idxQ.empty()) {
		int idx = idxQ.front();
		idxQ.pop();
		// 경계검사 먼저하기
		if(idx >= len) { 
			ret = true;
			break;
		}

		// 방문했으면 다시 방문하지 않도록
		if(isVisited[idx]) {
			continue;
		} else {
			isVisited[idx] = true;
		}

		int first = s[idx] - startIdx;
		int second = 0;
		if((idx+1) < len) {
			// 다음 칸 조사
			second = s[idx + 1] - startIdx;
			if(isAlphaValid[first][second]) {
				idxQ.push(idx + 2);
			}
		}
		
		if(isAlphaValid[first][0]) {
			idxQ.push(idx + 1);
		}
		
	}
	delete []isVisited;
	return ret;

}
