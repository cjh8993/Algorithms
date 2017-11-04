#include <iostream>
#include <string>

using namespace std;

string board[5];

bool HasWord(int x, int y, string word)
{
	// �ֺ� Ž���� ���� ��
	int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
	int dy[8] = { -1, -1, -1, 0, 0 , 1, 1, 1 };

	// ������ ���� �ʰ���
	if (x < 0 || x>4 || y < 0 || y>4)
		return false;

	// �ܾ��� ù���ڰ� ��ġ�� ������
	else if (word[0] != board[x][y])
		return false;

	// �ܾ��� ������ ���ڱ��� Ž�� ���������� �Ǵ� ���ܾ �ѱ����̰� ã������
	else if (word.length() == 1)
		return true;

	// �ѱ��ھ� ã�ư��� ���ϋ�
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
	// �׽�Ʈ ���̽� �� �Է�
	int testCaseNum;
	cin >> testCaseNum;

	for (int n = 0; n < testCaseNum; n++)
	{
		// ���� �Է�
		for (int i = 0; i < 5; i++)
		{
			cin >> board[i];
		}

		// �ܾ� �� �Է�
		int wordNum;
		cin >> wordNum;

		// �ܾ� �Է�
		string* word = new string[wordNum];
		for (int i = 0; i < wordNum; i++)
		{
			cin >> word[i];
		}

		// �ܾ� Ž��
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