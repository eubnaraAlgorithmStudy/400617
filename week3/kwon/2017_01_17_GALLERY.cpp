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
int G; // 갤러리
int H; // 복도
int ** hallinfo;

void NODE::Getinfo(int i)
{
	for (int j = 0; j < H; j++)
	{
		if (hallinfo[j][0] != i)
			continue; // 최적화 위해 아닌 경우를 제외,,
		else // 연결상태 확인 G가 일치하면 연결된 배열 // 추후에 최적화 가능할듯,,,
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
		// G H 정보 받기 위한 구조체 배열과 복도배열
		//node = (NODE *)malloc(sizeof(NODE) * G); <- 이건 왜 오버플로우상태로 초기화되는지,,,,
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

		// 정보 배열 채우기
		for (int i = 0; i < G; i++)
		{
			node[i].Getinfo(i);
		}
		// 연결 상태 계산 및 필요 카메라 수 계산
		printf("%d\n", Calcameras());

		free(hallinfo);
	}
	return 0;
}

