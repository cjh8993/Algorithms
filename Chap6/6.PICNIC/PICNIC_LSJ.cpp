#include <iostream>

using namespace std;

int g_studentNum;
bool** g_areFriends;
int possibleCaseCounter = 0;
bool MakePair(bool* students);

int main()
{
	// 테스트 케이스 수 입력
	int testCaseNum;
	cin >> testCaseNum;

	for (int i = 0; i < testCaseNum; i++)
	{
		// 학생 수 입력
		int studentNum;
		cin >> studentNum;
		g_studentNum = studentNum;

		// 학생 행렬 생성 & 초기화 (짝 유무)
		bool* students = new bool[studentNum];
		for (int j = 0; j < studentNum; j++)
		{
			students[j] = false;
		}

		// 친구 쌍의 수 입력
		int pairNum;
		cin >> pairNum;

		// 서로 친구 사이인지 아닌지 저장하는 행렬 생성 & 초기화
		bool** areFriends = new bool*[studentNum];
		for (int j = 0; j < studentNum; j++)
		{
			areFriends[j] = new bool[studentNum];
		}
		for (int j = 0; j < studentNum; j++)
		{
			for (int k = 0; k < studentNum; k++)
			{
				areFriends[j][k] = false;
			}
		}
		g_areFriends = areFriends;

		// 서로 친구인 두 학생의 번호 입력받아서 위에서 생성한 행렬에 저장
		int tempStudent1;
		int tempStudent2;
		for (int j = 0; j < pairNum * 2; j++)
		{
			if (j % 2 == 0)
				cin >> tempStudent1;
			else
			{
				cin >> tempStudent2;
				areFriends[tempStudent1][tempStudent2] = areFriends[tempStudent2][tempStudent1] = true;
			}
		}		

		/* 친구 여부 저장 행렬 테스트 출력
		for (int x = 0; x < studentNum; x++)
		{
			for (int y = 0; y < studentNum; y++)
			{
				cout << " " << areFriends[x][y];
			}
			cout << endl;
		}
		*/

		// 가능한 경우의 수 계산
		MakePair(students);
		cout << possibleCaseCounter << endl;
		possibleCaseCounter = 0;
	}

	return 0;
}

bool MakePair(bool* students)
{
	int firstFalseIndex = -1;

	// 짝이 없는 첫 학생 인덱스 탐색
	for (int i = 0; i < g_studentNum; i++)
	{
		if (students[i] == false)
		{
			firstFalseIndex = i;
			break;
		}
	}

	// 모두 짝이 있으면 성공
	if (firstFalseIndex == -1)
	{
		possibleCaseCounter++;
		return true;
	}

	// 찾기
	for (int i = firstFalseIndex + 1; i < g_studentNum; i++)
	{
		if (students[i] == false && g_areFriends[firstFalseIndex][i] == true)
		{
			students[firstFalseIndex] = students[i] = true;
			MakePair(students);
			students[firstFalseIndex] = students[i] = false;
		}
	}
}