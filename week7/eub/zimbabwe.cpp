#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;


int c;
int m;
int len;

int cmpFunc (const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}

const int MOD = 1000000007;
string e;
string digit;
int n;
int cache[1<<14][20][2];


int price(int index, int taken, int mod, int less)
{
	if (index == n)
	{
		return (less && mod == 0) ? 1 : 0;
	}

	int& ret = cache[taken][mod][less];
	if (ret != -1)
	{
		return ret;
	}
	ret = 0;

	for (int next = 0; next < n; next++)
	{
		if ((taken & (1 << next)) == 0)
		{
			if (!less && e[index] < digit[next])
				continue;

			if (next > 0 && digit[next - 1] == digit[next] && (taken & (1 << (next - 1))) == 0)
				continue;

			int nextTaken = taken | (1 << next);
			int nextMod = (mod * 10 + digit[next] - '0') % m;
			int nextLess = less || e[index] > digit[next];
			ret += price(index + 1, nextTaken, nextMod, nextLess);
			ret %= MOD;

		}
	}
	return ret;
}


int main(void) {

  scanf("%d", &c);

  while(c--) {
    memset(cache, -1, sizeof(int)*(1<<14)*20*2);

    cin >> e >> m;
    n = e.length();
    digit = e;

    // 순서대로 문자 정렬하기
    // 문자가 많아봐야 14개니까 버블정렬 사용
    for(int i = 0; i < n - 1; i++) {
      for(int j = 0; j < n - 1 - i; j++) {
        if(digit[j+1] < digit[j]) {
          char tmp = digit[j];
          digit[j] = digit[j+1];
          digit[j+1] = tmp;
        }
      }
    }
    cout << price(0, 0, 0, 0) << endl;

  }


  return 0;
}
