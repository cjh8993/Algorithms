#include <iostream>
#include <string>

using namespace std;

bool BoggleChecker(string* pannel, string input);
bool BoggleNearChecker(string* pannel, string c_input, int xidx, int yidx, int no_idx);

int main()
{
	int cases;
	cin >> cases;

	while (cases--) {
		//Boggle Pannel
		string pannel[5];
		for (int i = 0; i < 5; i++)
		{
			cin >> pannel[i];
		}

		//No. of check
		int n_input;
		cin >> n_input;

		//Boggle Checker
		for (int i = 0; i < n_input; i++)
		{
			string input;
			cin >> input;

			//ANSWER
			string answer;
			if (BoggleChecker(pannel, input))
				cout << input << " YES" << endl;
			else
				cout << input << " NO" << endl;
		}
	}	
}

bool BoggleChecker(string* pannel, string input)
{
	for (int i = 0; i < 5; i++)
	{
		//i => y
		for (int j = 0; j < 5; j++)
		{
			//j => x
			if (pannel[i][j] == input[0])
			{
				if (BoggleNearChecker(pannel, input, j, i, 1))
					return true;
			}
		}
	}

	return false;
}

bool BoggleNearChecker(string* pannel, string input, int xidx, int yidx, int no_idx)
{
	if (input.size() <= no_idx) return true;

	bool b_ret = false;

	int check_idx_x[] = { xidx + 1, xidx , xidx - 1 };
	int check_idx_y[] = { yidx + 1, yidx , yidx - 1 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (check_idx_x[i] >= 0 && check_idx_y[j] >= 0)   //값이 양수일때만 검사.
			{
				int check[] = { check_idx_x[i], check_idx_y[j] };
				if (i != j || j != 1)
				{
					//i == j == 1을 제외한 모든 경우(이건 자기자신이니 빼고..)
					if (input[no_idx] == pannel[check[1]][check[0]])
					{
						b_ret = BoggleNearChecker(pannel, input, check[0], check[1], no_idx + 1);
					}
				}
			}
		}
	}

	return b_ret;
}