// Header files inclusion
#include <iostream>

// Define namespace
using namespace std;

// Define constants
#define MAX 10

// Global variables declare
int n; // Number of friends (ģ���� �� 2<=n<=10)
int m; // Number of pairs (ģ�� ���� �� 0<=m<=n*(n-1)/2)
bool friends[MAX][MAX]; // i, j�� ģ�� ����, true or false
bool matched[MAX]; // ¦ ����


// Declare function
int MATCHING(int pairs, int n, int * result);

int main(void) 
{
   	/* �Ʒ� freopen �Լ��� sample_input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� sample_input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�
   	   �� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
   	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. 
	 freopen("sample_input.txt", "r", stdin);
	
	setbuf �Լ��� ������� ������, ������ ���α׷��� ���� '�ð� �ʰ�'�� ���� ���� �Ǿ��� ��,
	   printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	   �ð� �ʰ� ������ ����� ��� ������ �ް��� �ϽŴٸ� "setbuf(stdout, NULL);" �� ����Ͻñ� �ٶ��ϴ�. 
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
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
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
		
		// �� �κп��� ������ ����Ͻʽÿ�.
		cout << result << endl;
	}

	return 0; // �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
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
	for(int j = i + 1; j < n; j++) // ��¥�� 0���� ����
	{
		if(matched[j] == true)
		{
			continue; // ¦�ִ� ��� ���� 
		}
		if(friends[i][j] == true && friends[j][i] == true) 
		{
			// ��Ī �Ǿ��ٰ� ǥ���� ��, �� ���� ������ �������� ����
			// �Լ� ȣ���Ͽ� ¦���� �� �ִ� ����� ���� �ݿ� 
			matched[i] = matched[j] = true;
			if(MATCHING(pairs + 2, n, result) == 1)
			{
				(*result)++;
			}
			// i�� ¦�� �ٸ� ����� ��쵵 ���� ���� �ϹǷ�,  
			// ��Ī���� �ʾҴٰ� ǥ�� ��, ��������� ���� �������� �Ѿ� 
			matched[i] = matched[j] = false;
		}
	}
	
	return 0;
}

