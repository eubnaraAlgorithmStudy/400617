#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
// 1줄에 10개씩 정렬, 26개 알파벳, 인덱스는 1부터시작
enum { _a=1, _b, _c, _d, _e, _f, _g, _h, _i, _j, 
		_k, _l, _m, _n, _o, _p, _q, _r, _s, _t, 
		_u, _v, _w, _x, _y, _z};

bool isAlphaValid[26+1][26+1];



//TODO: new 연산을 없애기 위해 2차원 배열로 모두 변경하는 작업
int startIdx = 'a' - 1;
bool canMakeSentence(char* s, int len);

int main(void) {
	// index는 1부터 시작
	// a: c, g, l, m, r, s, t, u
	isAlphaValid[_a][_c] = true;
	isAlphaValid[_a][_g] = true;
	isAlphaValid[_a][_l] = true;
	isAlphaValid[_a][_m] = true;
	isAlphaValid[_a][_r] = true;
	isAlphaValid[_a][_s] = true;
	isAlphaValid[_a][_t] = true;
	isAlphaValid[_a][_u] = true;

	//b: a, e, h, i, k, r
	isAlphaValid[_b][0] = true;
	isAlphaValid[_b][_a] = true;
	isAlphaValid[_b][_e] = true;
	isAlphaValid[_b][_h] = true;
	isAlphaValid[_b][_i] = true;
	isAlphaValid[_b][_k] = true;
	isAlphaValid[_b][_r] = true;

	//c: a, d, e, f, l, m, n, o, r, s, u
	isAlphaValid[_c][0] = true;
	isAlphaValid[_c][_a] = true;
	isAlphaValid[_c][_d] = true;
	isAlphaValid[_c][_e] = true;
	isAlphaValid[_c][_f] = true;
	isAlphaValid[_c][_l] = true;
	isAlphaValid[_c][_m] = true;
	isAlphaValid[_c][_n] = true;
	isAlphaValid[_c][_o] = true;
	isAlphaValid[_c][_r] = true;
	isAlphaValid[_c][_s] = true;
	isAlphaValid[_c][_u] = true;

	//d: b, s, y
	isAlphaValid[_d][_b] = true;
	isAlphaValid[_d][_s] = true;
	isAlphaValid[_d][_y] = true;

	//e: r, s, u
	isAlphaValid[_e][_r] = true;
	isAlphaValid[_e][_s] = true;
	isAlphaValid[_e][_u] = true;

	//f: e, l, m, r
	isAlphaValid[_f][0] = true;
	isAlphaValid[_f][_e] = true;
	isAlphaValid[_f][_l] = true;
	isAlphaValid[_f][_m] = true;
	isAlphaValid[_f][_r] = true;

	//g: a, d, e
	isAlphaValid[_g][_a] = true;
	isAlphaValid[_g][_d] = true;
	isAlphaValid[_g][_e] = true;

	//h: e, f, g, o, s
	isAlphaValid[_h][0] = true;
	isAlphaValid[_h][_e] = true;
	isAlphaValid[_h][_f] = true;
	isAlphaValid[_h][_g] = true;
	isAlphaValid[_h][_o] = true;
	isAlphaValid[_h][_s] = true;

	//i: n, r
	isAlphaValid[_i][0] = true;
	isAlphaValid[_i][_n] = true;
	isAlphaValid[_i][_r] = true;

	//j: nothing

	//k: n
	isAlphaValid[_k][0] = true;
	isAlphaValid[_k][_n] = true;

	//l: a, i, r, u, v
	isAlphaValid[_l][_a] = true;
	isAlphaValid[_l][_i] = true;
	isAlphaValid[_l][_r] = true;
	isAlphaValid[_l][_u] = true;
	isAlphaValid[_l][_v] = true;

	//m: d, g, n, o, t
	isAlphaValid[_m][_d] = true;
	isAlphaValid[_m][_g] = true;
	isAlphaValid[_m][_n] = true;
	isAlphaValid[_m][_o] = true;
	isAlphaValid[_m][_t] = true;

	//n: a, b, d, e, i, o, p 
	isAlphaValid[_n][0] = true;
	isAlphaValid[_n][_a] = true;
	isAlphaValid[_n][_b] = true;
	isAlphaValid[_n][_d] = true;
	isAlphaValid[_n][_e] = true;
	isAlphaValid[_n][_i] = true;
	isAlphaValid[_n][_o] = true;
	isAlphaValid[_n][_p] = true;

	//o: s
	isAlphaValid[_o][0] = true;
	isAlphaValid[_o][_s] = true;

	//p: a, b, d, m, o, r, t, u
	isAlphaValid[_p][0] = true; 
	isAlphaValid[_p][_a] = true;
	isAlphaValid[_p][_b] = true;
	isAlphaValid[_p][_d] = true;
	isAlphaValid[_p][_m] = true;
	isAlphaValid[_p][_o] = true;
	isAlphaValid[_p][_r] = true;
	isAlphaValid[_p][_t] = true;
	isAlphaValid[_p][_u] = true;

	//q: nothing

	//r: a, b, e, f, g, h, n, u 
	isAlphaValid[_r][_a] = true;
	isAlphaValid[_r][_b] = true;
	isAlphaValid[_r][_e] = true;
	isAlphaValid[_r][_f] = true;
	isAlphaValid[_r][_g] = true;	
	isAlphaValid[_r][_h] = true;
	isAlphaValid[_r][_n] = true;
	isAlphaValid[_r][_u] = true;

	//s: b, c, e, g, i, m, n, r 
	isAlphaValid[_s][0] = true;
	isAlphaValid[_s][_b] = true;
	isAlphaValid[_s][_c] = true;
	isAlphaValid[_s][_e] = true;
	isAlphaValid[_s][_g] = true;
	isAlphaValid[_s][_i] = true;
	isAlphaValid[_s][_m] = true;
	isAlphaValid[_s][_n] = true;
	isAlphaValid[_s][_r] = true;

	//t: a, b, c, e, h, i, l, m
	isAlphaValid[_t][_a] = true;	
	isAlphaValid[_t][_b] = true;	
	isAlphaValid[_t][_c] = true;
	isAlphaValid[_t][_e] = true;
	isAlphaValid[_t][_h] = true;
	isAlphaValid[_t][_i] = true;
	isAlphaValid[_t][_l] = true;	
	isAlphaValid[_t][_m] = true;

	//u: v: w:
	isAlphaValid[_u][0] = true;
	isAlphaValid[_v][0] = true;
	isAlphaValid[_w][0] = true;

	//x: e
	isAlphaValid[_x][_e] = true;	

	//y: b
	isAlphaValid[_y][0] = true;
	isAlphaValid[_y][_b] = true;

	//z: n, r
	isAlphaValid[_z][_n] = true;
	isAlphaValid[_z][_r] = true;

	int T;
	char input[50001];
	scanf("%d",&T);
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
		if(isAlphaValid[first][0]) {
			idxQ.push(idx + 1);
		}
		if((idx+1) < len) {
			// 다음 칸 조사
			second = s[idx + 1] - startIdx;
			if(isAlphaValid[first][second]) {
				idxQ.push(idx + 2);
			}
		}
	}
	delete []isVisited;
	return ret;
}