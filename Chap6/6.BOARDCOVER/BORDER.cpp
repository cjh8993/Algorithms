#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct d_point {
	int dx;
	int dy;
};

struct p_set {
	d_point p[2];
};

class L_block {
public:
	p_set blocks[4];
	L_block()
	{
		blocks[0].p[0].dx = 1;
		blocks[0].p[0].dy = 0;
		blocks[0].p[1].dx = 1;
		blocks[0].p[1].dy = 1;


		blocks[1].p[0].dx = 0;
		blocks[1].p[0].dy = 1;
		blocks[1].p[1].dx = -1;
		blocks[1].p[1].dy = 1;


		blocks[2].p[0].dx = 0;
		blocks[2].p[0].dy = 1;
		blocks[2].p[1].dx = 1;
		blocks[2].p[1].dy = 1;


		blocks[3].p[0].dx = 1;
		blocks[3].p[0].dy = 0;
		blocks[3].p[1].dx = 0;
		blocks[3].p[1].dy = 1;

	}
};

L_block l_block = L_block();


bool dotChecker(char c)
{
	if (c == '.')
		return true;
	else
		return false;
}

void CurProcessChecker(vector<string> board, int x, int y)
{
	cout << "Cur Board!" << endl;
	for (int i = 0; i < board.size(); i++)
	{
		if(i == y)
			board[i][x] = 'O';
		cout << board[i] << endl;
	}

	cout << endl;
}

void Checker(vector<string> board, int x_start, int y_start, int* counter)
{
	//y방향 체크
	for(int y=0; y<board.size();y++)
	{
		//x방향 체크
		for (int x = 0; x < board[y].size(); x++)
		{
			//만약 마지막까지 검색했다면.
			if (board.size() == y +1
				&& board[0].size()  == x +1)
			{
				//CurProcessChecker(board, x, y);
				(*counter)++;
				return;
			}

			if (dotChecker(board[y][x]))
			{
				bool iswork = false;

				for (int i = 0; i < 4; i++)
				{
					int cx1 = x + l_block.blocks[i].p[0].dx;
					int cy1 = y + l_block.blocks[i].p[0].dy;
					int cx2 = x + l_block.blocks[i].p[1].dx;
					int cy2 = y + l_block.blocks[i].p[1].dy;

					if (cy1 < board.size() && cx1 < board[y].size()
						&& cy2 < board.size() && cx2 < board[y].size()
						&& dotChecker(board[cy1][cx1])
						&& dotChecker(board[cy2][cx2]))
					{
						iswork = true;
						vector<string> n_board = board;
						//. -> # 변경
						n_board[y][x] = '#';
						n_board[cy1][cx1] = '#';
						n_board[cy2][cx2] = '#';

						//재탐색
						Checker(n_board, x, y, counter);
					}
				}
				
				//만약 점이있지만 대입할 수 없는 경우
				return;
			}
		}
	}
}


int main()
{
	int cases;
	cin >> cases;
	vector<int> counters;
	counters.reserve(cases);
	while (cases--)
	{
		//Board Input
		int H, W;
		cin >> H;
		cin >> W;

		//세로벡터 초기화
		vector<string> board;
		board.reserve(H);

		//board 입력
		for (int i = 0; i < H; i++)
		{
			string board_w;
			cin >> board_w;

			board.push_back(board_w);
		}

		int counter = 0;
		
		Checker(board, 0, 0, &counter);

		counters.push_back(counter);
	}
	
	//답 출력
	for (vector<int>::iterator it = counters.begin(); it != counters.end(); ++it)
	{
		cout << *it << endl;
	}
}