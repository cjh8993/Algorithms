#include <iostream>

using namespace std;

int g_studentNum;
bool** g_areFriends;
int possibleCaseCounter = 0;
bool MakePair(bool* students);

int main()
{
	// �׽�Ʈ ���̽� �� �Է�
	int testCaseNum;
	cin >> testCaseNum;

	for (int i = 0; i < testCaseNum; i++)
	{
		// �л� �� �Է�
		int studentNum;
		cin >> studentNum;
		g_studentNum = studentNum;

		// �л� ��� ���� & �ʱ�ȭ (¦ ����)
		bool* students = new bool[studentNum];
		for (int j = 0; j < studentNum; j++)
		{
			students[j] = false;
		}

		// ģ�� ���� �� �Է�
		int pairNum;
		cin >> pairNum;

		// ���� ģ�� �������� �ƴ��� �����ϴ� ��� ���� & �ʱ�ȭ
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

		// ���� ģ���� �� �л��� ��ȣ �Է¹޾Ƽ� ������ ������ ��Ŀ� ����
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

		/* ģ�� ���� ���� ��� �׽�Ʈ ���
		for (int x = 0; x < studentNum; x++)
		{
			for (int y = 0; y < studentNum; y++)
			{
				cout << " " << areFriends[x][y];
			}
			cout << endl;
		}
		*/

		// ������ ����� �� ���
		MakePair(students);
		cout << possibleCaseCounter << endl;
		possibleCaseCounter = 0;
	}

	return 0;
}

bool MakePair(bool* students)
{
	int firstFalseIndex = -1;

	// ¦�� ���� ù �л� �ε��� Ž��
	for (int i = 0; i < g_studentNum; i++)
	{
		if (students[i] == false)
		{
			firstFalseIndex = i;
			break;
		}
	}

	// ��� ¦�� ������ ����
	if (firstFalseIndex == -1)
	{
		possibleCaseCounter++;
		return true;
	}

	// ã��
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