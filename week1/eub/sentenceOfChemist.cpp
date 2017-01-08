#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

// 1줄에 10개씩 정렬, 26개 알파벳, 인덱스는 1부터시작
enum { _a=1, _b, _c, _d, _e, _f, _g, _h, _i, _j, 
		_k, _l, _m, _n, _o, _p, _q, _r, _s, _t, 
		_u, _v, _w, _x, _y, _z};

class Node {
private:
	bool valid;
	
public:
	class Node* children[26+1];
	Node(bool v): valid(v) {}
	Node(): valid(false) {}

	bool isValid() { return valid; }
	void setValid() { valid = true; }
};

Node alpha[26+1];
int startIdx = 'a' - 1;
bool canMakeSentence(char* s, int len, int pos);

int main(void) {
	// index는 1부터 시작
	// a: c, g, l, m, r, s, t, u
	alpha[_a].children[_c] = new Node(true);
	alpha[_a].children[_g] = new Node(true);
	alpha[_a].children[_l] = new Node(true);
	alpha[_a].children[_m] = new Node(true);
	alpha[_a].children[_r] = new Node(true);
	alpha[_a].children[_s] = new Node(true);
	alpha[_a].children[_t] = new Node(true);
	alpha[_a].children[_u] = new Node(true);

	//b: a, e, h, i, k, r
	alpha[_b].setValid();
	alpha[_b].children[_a] = new Node(true);
	alpha[_b].children[_e] = new Node(true);
	alpha[_b].children[_h] = new Node(true);
	alpha[_b].children[_i] = new Node(true);
	alpha[_b].children[_k] = new Node(true);
	alpha[_b].children[_r] = new Node(true);

	//c: a, d, e, f, l, m, n, o, r, s, u
	alpha[_c].setValid();
	alpha[_c].children[_a] = new Node(true);
	alpha[_c].children[_d] = new Node(true);
	alpha[_c].children[_e] = new Node(true);
	alpha[_c].children[_f] = new Node(true);
	alpha[_c].children[_l] = new Node(true);
	alpha[_c].children[_m] = new Node(true);
	alpha[_c].children[_n] = new Node(true);
	alpha[_c].children[_o] = new Node(true);
	alpha[_c].children[_r] = new Node(true);
	alpha[_c].children[_s] = new Node(true);
	alpha[_c].children[_u] = new Node(true);

	//d: b, s, y
	alpha[_d].children[_b] = new Node(true);
	alpha[_d].children[_s] = new Node(true);
	alpha[_d].children[_y] = new Node(true);

	//e: r, s, u
	alpha[_e].children[_r] = new Node(true);
	alpha[_e].children[_s] = new Node(true);
	alpha[_e].children[_u] = new Node(true);

	//f: e, l, m, r
	alpha[_f].setValid();
	alpha[_f].children[_e] = new Node(true);
	alpha[_f].children[_l] = new Node(true);
	alpha[_f].children[_m] = new Node(true);
	alpha[_f].children[_r] = new Node(true);

	//g: a, d, e
	alpha[_g].children[_a] = new Node(true);
	alpha[_g].children[_d] = new Node(true);
	alpha[_g].children[_e] = new Node(true);

	//h: e, f, g, o, s
	alpha[_h].setValid();
	alpha[_h].children[_e] = new Node(true);
	alpha[_h].children[_f] = new Node(true);
	alpha[_h].children[_g] = new Node(true);
	alpha[_h].children[_o] = new Node(true);
	alpha[_h].children[_s] = new Node(true);

	//i: n, r
	alpha[_i].setValid();
	alpha[_i].children[_n] = new Node(true);
	alpha[_i].children[_r] = new Node(true);

	//j: nothing

	//k: n
	alpha[_k].setValid();
	alpha[_k].children[_n] = new Node(true);

	//l: a, i, r, u, v
	alpha[_l].children[_a] = new Node(true);
	alpha[_l].children[_i] = new Node(true);
	alpha[_l].children[_r] = new Node(true);
	alpha[_l].children[_u] = new Node(true);
	alpha[_l].children[_v] = new Node(true);

	//m: d, g, n, o, t
	alpha[_m].children[_d] = new Node(true);
	alpha[_m].children[_g] = new Node(true);
	alpha[_m].children[_n] = new Node(true);
	alpha[_m].children[_o] = new Node(true);
	alpha[_m].children[_t] = new Node(true);

	//n: a, b, d, e, i, o, p 
	alpha[_n].setValid();
	alpha[_n].children[_a] = new Node(true);
	alpha[_n].children[_b] = new Node(true);
	alpha[_n].children[_d] = new Node(true);
	alpha[_n].children[_e] = new Node(true);
	alpha[_n].children[_i] = new Node(true);
	alpha[_n].children[_o] = new Node(true);
	alpha[_n].children[_p] = new Node(true);

	//o: s
	alpha[_o].setValid();
	alpha[_o].children[_s] = new Node(true);

	//p: a, b, d, m, o, r, t, u
	alpha[_p].setValid(); 
	alpha[_p].children[_a] = new Node(true);
	alpha[_p].children[_b] = new Node(true);
	alpha[_p].children[_d] = new Node(true);
	alpha[_p].children[_m] = new Node(true);
	alpha[_p].children[_o] = new Node(true);
	alpha[_p].children[_r] = new Node(true);
	alpha[_p].children[_t] = new Node(true);
	alpha[_p].children[_u] = new Node(true);

	//q: nothing

	//r: a, b, e, f, g, h, n, u 
	alpha[_r].children[_a] = new Node(true);
	alpha[_r].children[_b] = new Node(true);
	alpha[_r].children[_e] = new Node(true);
	alpha[_r].children[_f] = new Node(true);
	alpha[_r].children[_g] = new Node(true);	
	alpha[_r].children[_h] = new Node(true);
	alpha[_r].children[_n] = new Node(true);
	alpha[_r].children[_u] = new Node(true);

	//s: b, c, e, g, i, m, n, r 
	alpha[_s].setValid();
	alpha[_s].children[_b] = new Node(true);
	alpha[_s].children[_c] = new Node(true);
	alpha[_s].children[_e] = new Node(true);
	alpha[_s].children[_g] = new Node(true);
	alpha[_s].children[_i] = new Node(true);
	alpha[_s].children[_m] = new Node(true);
	alpha[_s].children[_n] = new Node(true);
	alpha[_s].children[_r] = new Node(true);

	//t: a, b, c, e, h, i, l, m
	alpha[_t].children[_a] = new Node(true);	
	alpha[_t].children[_b] = new Node(true);	
	alpha[_t].children[_c] = new Node(true);
	alpha[_t].children[_e] = new Node(true);
	alpha[_t].children[_h] = new Node(true);
	alpha[_t].children[_i] = new Node(true);
	alpha[_t].children[_l] = new Node(true);	
	alpha[_t].children[_m] = new Node(true);

	//u: v: w:
	alpha[_u].setValid();
	alpha[_v].setValid();
	alpha[_w].setValid();

	//x: e
	alpha[_x].children[_e] = new Node(true);	

	//y: b
	alpha[_y].setValid();
	alpha[_y].children[_b] = new Node(true);

	//z:
	alpha[_z].children[_n] = new Node(true);
	alpha[_z].children[_r] = new Node(true);

	int T;
	char input[50001];
	scanf("%d",&T);
	for(int i=1; i<=T; i++) {
		scanf("%s",input);
		printf("Case #%d\n", i);
		if(canMakeSentence(input, strlen(input), 0)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}

	}





	return 0;
}

//입력은 소문자만 들어온다.
bool canMakeSentence(char* s, int len, int pos) {
	//길이를 넘어갔다면, 문자가 완성되었다는 것, true 반환
	if(len == pos) 
		return true;
	//한 글자로 된 원소 먼저 처리
	if(alpha[s[pos] - startIdx].isValid()) {
		if(canMakeSentence(s, len, pos+1))
			return true;
	}
	Node * p = &alpha[s[pos] - startIdx];
	//두 글자로 된 원소 처리
	pos = pos + 1;
	if(p->children[s[pos] - startIdx] != NULL && p->children[s[pos] - startIdx]->isValid()) {
		if(canMakeSentence(s, len, pos+1))
			return true;
	}

	return false;
}