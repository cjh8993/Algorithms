#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string piNum;

// ù ���� ���̵�
int PartialDifficulty(int firstIndex, int lastIndex);

// ��ü ���̵�
int cache[10000];
int TotalDifficulty(int index);
int main()
{
	int testCaseNum;
	cin >> testCaseNum;

	while (testCaseNum--)
	{
		cin >> piNum;
		fill_n(cache, 10000, -1);
		cout << TotalDifficulty(0) << endl;
	}

	return 0;
}

int PartialDifficulty(int firstIndex, int lastIndex)
{
	// ù ����
	string tempPiNum = piNum.substr(firstIndex, lastIndex - firstIndex + 1);

	// �� ���� �����϶� ���̵� 1
	if (tempPiNum == string(tempPiNum.size(), tempPiNum[0]))
		return 1;

	// �����ϰ� �����ϰų� �����ϴ��� Ȯ��
	bool hasSameGap = true;
	for (int i = 0; i < tempPiNum.size() - 1; i++)
	{
		if (tempPiNum[i + 1] - tempPiNum[i] != tempPiNum[1] - tempPiNum[0])
			hasSameGap = false;
	}

	// �����ϰ� ���� 1�̸� ���̵� 2, ���� 1�� �ƴϸ� ���̵� 5
	if (hasSameGap)
	{
		if (abs(tempPiNum[1] - tempPiNum[0]) == 1)
			return 2;
		else
			return 5;
	}

	// �ϳ� �ǳʶٰ� �������� �����ϴ��� Ȯ��
	bool hasSameNumAgain = true;
	for (int i = 0; i < tempPiNum.size(); i++)
	{
		if (tempPiNum[i] != tempPiNum[i % 2])
			hasSameNumAgain = false;
	}

	// �ϳ� �ǳʶٰ� �������� �����ϸ� ���̵� 4
	if (hasSameNumAgain)
		return 4;

	// �ش� ������ ���̵� 10
	return 10;
}

int TotalDifficulty(int index)
{
	// ������ �ε����϶�
	if (index == piNum.size())
		return 0;

	// �޸������̼�
	int& ret = cache[index];
	if (ret != -1)
		return ret;

	// 3~5 �������� �߶� ���ȣ��
	ret = 33330;
	for (int i = 3; i < 6; i++)
	{
		if (index + i <= piNum.size())
			ret = min(ret, PartialDifficulty(index, index + i - 1) + TotalDifficulty(index + i));
	}
	
	return ret;
}