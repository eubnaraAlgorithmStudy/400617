#include <iostream>
#include <stdio.h>
#include <queue>
#include <list>
#include <stdlib.h>

using namespace std;

class NODE
{
public:
	bool isGx;
	queue<int> Gxqueue;
	NODE()
	{
		isGx = true;
		while (!Gxqueue.empty()) Gxqueue.pop();
	}
	void Getinfo(int i);
};
NODE * node;
int G; // ������
int H; // ����
int ** hallinfo;

void NODE::Getinfo(int i)
{
	for (int j = 0; j < H; j++)
	{
		if (hallinfo[j][0] != i)
			continue; // ����ȭ ���� �ƴ� ��츦 ����,,
		else // ������� Ȯ�� G�� ��ġ�ϸ� ����� �迭 // ���Ŀ� ����ȭ �����ҵ�,,,
		{
			int temp = hallinfo[j][1];
			Gxqueue.push(temp);
		}
	}
}
int Calcameras()
{
	int result = 0;
	int temp = 0;

	for (int i = 0; i < G; i++)
	{
		if (node[i].isGx == true)
		{
			if (node[i].Gxqueue.empty())
			{
				result++;
			}
			else
			{
				do
				{
					temp = node[i].Gxqueue.front();
					node[temp].isGx = false;
					node[i].Gxqueue.pop();
				} while (!(node[i].Gxqueue.empty()));
				node[i].isGx = false;
				result++;
			}
		}
	}
	return result;
}
int main(void)
{
	int T = 0;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &G, &H);
		// G H ���� �ޱ� ���� ����ü �迭�� �����迭
		//node = (NODE *)malloc(sizeof(NODE) * G); <- �̰� �� �����÷ο���·� �ʱ�ȭ�Ǵ���,,,,
		node = new NODE[G];
		hallinfo = (int **)malloc(sizeof(int *) * H);
		for (int i = 0; i < H; i++)
		{
			hallinfo[i] = (int *)malloc(sizeof(int) * 2);
		}

		for (int i = 0; i < H; i++)
		{
			scanf("%d %d", &hallinfo[i][0], &hallinfo[i][1]);
		}

		// ���� �迭 ä���
		for (int i = 0; i < G; i++)
		{
			node[i].Getinfo(i);
		}
		// ���� ���� ��� �� �ʿ� ī�޶� �� ���
		printf("%d\n", Calcameras());

		free(hallinfo);
	}
	return 0;
}

