/*
4
321 3
123 3
422 2
12738173912 7

5
0
2
11033
*/
#include <cstdio>
#include <string>
using namespace std;

const int MOD = 1000000007;
string e;
string digit;
int n;
int m;
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

			if (next > 0 && digit[next - 1] == digit[next] && (taken & (1 << next - 1)) == 0)
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
int main(void)
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s %d", &e, &m);
		
	}
	return 0;
}