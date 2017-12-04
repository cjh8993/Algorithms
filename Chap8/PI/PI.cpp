#include <iostream>
#include <string>
#define MAX_LENGTH 10000

using namespace std;


string _data;
int cache[MAX_LENGTH];

//Score 1
bool is_all_the_same(string s)
{
	if (s.find_first_not_of(s[0]) == -1)
		return true;
	else
		return false;
}

//Score 2
bool is_monotone_increaing(string s)
{
	int s0 = s[0] - '0';
	for (int i = 1; i < s.size(); i++)
	{
		s0++;
		int si = s[i] - '0';
		if (s0 != si) return false;
	}

	return true;
}

//Score 4
bool is_alternate_occurence(string s)
{
	char pattern[2] = { s[0], s[1] };
	for (int i = 2; i < s.size(); i++) {
		if (s[i] != pattern[i%2]) return false;
	}

	return true;
}

//Score 5
bool is_arithmetical_progression(string s)
{
	int ds = s[1] - s[0];
	for (int i = 2; i < s.size(); i++) {
		if (ds != (s[i] - s[i - 1])) return false;
	}

	return true;
}

int CheckScore(int idx, int length)
{
	int score = 0;
	string s = _data.substr(idx, length);

	//socre 1 : all the same.
	if (is_all_the_same(s))
		score = 1;
	//score 2 : 1씩 증가
	else if (is_monotone_increaing(s))
		score = 2;
	else if (is_alternate_occurence(s))
		score = 4;
	else if (is_arithmetical_progression(s))
		score = 5;
	else
		score = 10;

	return score;
}


int GetAnswer(int idx)
{
	int index = 0;
	cache[2] = CheckScore(0, 3);
	cache[3] = CheckScore(0, 4);
	cache[4] = CheckScore(0, 5);

 	for (int i = 5; i < _data.size(); i++)
	{
		cache[i] = CheckScore(i,3);
	}


	return 0;
}

int main()
{
	int cases;
	cin >> cases;

	
	//Cache 초기화
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		cache[i] = -1;
	}

	while (cases--)
	{
		//Data 받기
		cin >> _data;

		int ans = GetAnswer(2);
		cout << ans << endl;
	}
}