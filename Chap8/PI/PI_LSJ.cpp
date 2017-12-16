#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string piNum;

// 첫 조각 난이도
int PartialDifficulty(int firstIndex, int lastIndex);

// 전체 난이도
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
	// 첫 조각
	string tempPiNum = piNum.substr(firstIndex, lastIndex - firstIndex + 1);

	// 다 같은 숫자일때 난이도 1
	if (tempPiNum == string(tempPiNum.size(), tempPiNum[0]))
		return 1;

	// 일정하게 증가하거나 감소하는지 확인
	bool hasSameGap = true;
	for (int i = 0; i < tempPiNum.size() - 1; i++)
	{
		if (tempPiNum[i + 1] - tempPiNum[i] != tempPiNum[1] - tempPiNum[0])
			hasSameGap = false;
	}

	// 일정하고 차가 1이면 난이도 2, 차가 1이 아니면 난이도 5
	if (hasSameGap)
	{
		if (abs(tempPiNum[1] - tempPiNum[0]) == 1)
			return 2;
		else
			return 5;
	}

	// 하나 건너뛰고 같은수가 등장하는지 확인
	bool hasSameNumAgain = true;
	for (int i = 0; i < tempPiNum.size(); i++)
	{
		if (tempPiNum[i] != tempPiNum[i % 2])
			hasSameNumAgain = false;
	}

	// 하나 건너뛰고 같은수가 등장하면 난이도 4
	if (hasSameNumAgain)
		return 4;

	// 해당 없으면 난이도 10
	return 10;
}

int TotalDifficulty(int index)
{
	// 마지막 인덱스일때
	if (index == piNum.size())
		return 0;

	// 메모이제이션
	int& ret = cache[index];
	if (ret != -1)
		return ret;

	// 3~5 조각으로 잘라서 재귀호출
	ret = 33330;
	for (int i = 3; i < 6; i++)
	{
		if (index + i <= piNum.size())
			ret = min(ret, PartialDifficulty(index, index + i - 1) + TotalDifficulty(index + i));
	}
	
	return ret;
}