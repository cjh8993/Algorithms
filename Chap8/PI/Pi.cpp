#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <time.h>

int test = 0;
const int INF = 987654321;
std::string A;

int cache[10002];
int Memorize(int indexA);
int Classify(int a, int b);

int main()
{
	std::cin >> test;
	for (int i = 0; i < test; ++i)
	{
		for (int i = 0; i < 10002; i++)
		{
			cache[i] = -1;
		}
		std::cin >> A;
		std::cout << Memorize(0) << std::endl;
	}
	return 0;
}

int Classify(int a, int b)
{
	std::string M = A.substr(a, b - a + 1);
	if (M == std::string(M.size(), M[0])) return 1;
	bool progressive = true;
	for (int i = 0; i < M.size() - 1; ++i)
		if (M[i + 1] - M[i] != M[1] - M[0])
			progressive = false;
	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;
	bool alternating = true;
	for (int i = 0; i < M.size(); ++i)
		if (M[i] != M[i % 2])
			alternating = false;
	if (alternating) return 4;
	if (progressive) return 5;
	return 10;
}

int Memorize(int begin)
{
	if (begin == A.size()) return 0;
	int& ret = cache[begin];
	if (ret != -1) return ret;
	ret = INF;
	for (int L = 3; L <= 5; ++L)
		if (begin + L <= A.size())
			ret = std::min(ret, Memorize(begin + L) + Classify(begin, begin + L - 1));
	return ret;
}
