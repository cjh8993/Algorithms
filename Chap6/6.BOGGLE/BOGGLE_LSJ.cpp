#include <iostream>
#include <string>

using namespace std;

string board[5];

bool HasWord(int x, int y, string word)
{
	// 주변 탐색을 위한 값
	int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
	int dy[8] = { -1, -1, -1, 0, 0 , 1, 1, 1 };

	// 보드판 영역 초과시
	if (x < 0 || x>4 || y < 0 || y>4)
		return false;

	// 단어의 첫글자가 위치에 없을때
	else if (word[0] != board[x][y])
		return false;

	// 단어의 마지막 글자까지 탐색 성공했을때 또는 대상단어가 한글자이고 찾았을때
	else if (word.length() == 1)
		return true;

	// 한글자씩 찾아가는 중일떄
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (HasWord(x + dx[i], y + dy[i], word.substr(1)))
				return true;
		}
	}

}

int main()
{
	// 테스트 케이스 수 입력
	int testCaseNum;
	cin >> testCaseNum;

	for (int n = 0; n < testCaseNum; n++)
	{
		// 보드 입력
		for (int i = 0; i < 5; i++)
		{
			cin >> board[i];
		}

		// 단어 수 입력
		int wordNum;
		cin >> wordNum;

		// 단어 입력
		string* word = new string[wordNum];
		for (int i = 0; i < wordNum; i++)
		{
			cin >> word[i];
		}

		// 단어 탐색
		for (int i = 0; i < wordNum; i++)
		{
			bool findWord = false;
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (HasWord(j, k, word[i]) == true)
					{
						findWord = true;
						break;
					}
				}
				if (findWord == true)
					break;
			}

			if (findWord == true)
				cout << word[i] << " YES" << endl;
			else
				cout << word[i] << " NO" << endl;
		}
	}

	return 0;
}