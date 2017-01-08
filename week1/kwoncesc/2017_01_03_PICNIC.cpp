// Header files inclusion
#include <iostream>

// Define namespace
using namespace std;

// Define constants
#define MAX 10

// Global variables declare
int n; // Number of friends (친구의 수 2<=n<=10)
int m; // Number of pairs (친구 쌍의 수 0<=m<=n*(n-1)/2)
bool friends[MAX][MAX]; // i, j의 친구 유무, true or false
bool matched[MAX]; // 짝 유무


// Declare function
int MATCHING(int pairs, int n, int * result);

int main(void) 
{
   	/* 아래 freopen 함수는 sample_input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 sample_input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인 PC 에서 테스트 할 때는, 입력값을 sample_input.txt에 저장한 후 freopen 함수를 사용하면
   	   그 아래에서 scanf 함수를 사용하여 표준입력 대신 sample_input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
   	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. 
	 freopen("sample_input.txt", "r", stdin);
	
	setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 '시간 초과'로 강제 종료 되었을 때,
	   printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	   시간 초과 전까지 실행된 결과 점수를 받고자 하신다면 "setbuf(stdout, NULL);" 를 사용하시기 바랍니다. 
	*/
	setbuf(stdout, NULL);

	// Local variables declare
	int T;
	int test_case;
	int i = 0;
	int j = 0;

	// Statements
	cin >> T;
	for(test_case = 1; test_case <= T; test_case++) 
	{
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        cin >> n >> m;
        
        // Reset friend's infomation to false
        for(i = 0; i < n; i++)
        {
        	for(j = 0; j < n; j++)
        	{
        		friends[i][j] = friends[j][i] = false;
			}
		}
		// Reset matching infomation
		for (i = 0; i < MAX; i++)
		{
			matched[i] = false;
		}
		
		// Get friend's infomation
		for(int temp = 0; temp < m; temp++)
		{
			cin >> i >> j;
			friends[i][j] = friends[j][i] = true;
		}
		
		int result = 0;
		MATCHING(0, n, &result);
		
		// 이 부분에서 정답을 출력하십시오.
		cout << result << endl;
	}

	return 0; // 정상종료 시 반드시 0을 리턴해야 합니다.
}

// Function definition
int MATCHING(int pairs, int n, int * result)
{
	// Local variables declare
	int i = 0;

	// Statements
	if(pairs == n)
		return 1; // all matched, teminated condition
		
	for(i = 0; i < n; i++)
	{
		if(matched[i] == false)
		{
			break;
		}
	}
	for(int j = i + 1; j < n; j++) // 어짜피 0부터 시작
	{
		if(matched[j] == true)
		{
			continue; // 짝있는 사람 무시 
		}
		if(friends[i][j] == true && friends[j][i] == true) 
		{
			// 매칭 되었다고 표시한 뒤, 이 둘을 제외한 나머지에 대해
			// 함수 호출하여 짝지을 수 있는 경우의 수를 반영 
			matched[i] = matched[j] = true;
			if(MATCHING(pairs + 2, n, result) == 1)
			{
				(*result)++;
			}
			// i의 짝이 다른 사람인 경우도 세어 봐야 하므로,  
			// 매칭되지 않았다고 표시 후, 다음사람에 대한 포문으로 넘어 
			matched[i] = matched[j] = false;
		}
	}
	
	return 0;
}

