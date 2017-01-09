// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


string givenStr[119] = {
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
    "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
    "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
    "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
    "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
    "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
    "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
    "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
    "No", "Lr"
};

vector<vector<string> > S;

// 주어진 화학기호에 대해 초기화
void initialize() {
    int nLen = 119;//givenStr.size();
    for (int i=0; i<nLen; i++) {
        givenStr[i][0] += 32;
        int inIndex = givenStr[i][0] - 'a';
        S[inIndex].push_back(givenStr[i]);
    }
}

// string 처음부터 nst가 까지의 문자열이 화학기호에 포함되는지 확인
bool isCharIn(string str, int nst) {
    bool isIn = false;
    int inIndex = str[0]-'a'; // 첫 문자로 해당 위치의 배열을 찾는다
    vector<string> vS = S[inIndex];
    int nLen = vS.size();
    string comStr = str.substr(0, nst); // 비교할 문자열
    
    for (int i=0; i<nLen; i++) {
        if (comStr.compare(vS[i]) == 0) {
            isIn = true;
            break;
        }
    }
    
    return isIn;
}

// 완전 탐색
bool process(string str) {
    int nLen = str.length();
    if (nLen == 0)
        return true;
    
    if (isCharIn(str, 1)) {
        return process(str.substr(1, nLen-1));
    }
    
    if (nLen >= 2 && isCharIn(str, 2)) {
        return process(str.substr(2, nLen-2));
    }
    
    return false;
}

int main(int argc, char** argv) {
    
    setbuf(stdout, NULL);
    
    int TC;
    int test_case;
    
    S.assign(26, vector<string> ());
    initialize();
    
    scanf("%d", &TC);	// cin 사용 가능
    for(test_case = 1; test_case <= TC; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오.
        
        string T_STR;
        cin >> T_STR;
        bool ans = process(T_STR);
        
        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);	// cout 사용 가능
        if (ans) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
