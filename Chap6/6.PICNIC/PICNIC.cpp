#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

struct BF{
    int f_set[2];
   
    //대소비교를 위한 연산자.
    bool operator<(const BF& other)
    {
            if( f_set[0] < other.f_set[0])
                    return true;
            else
                    return false;
    };

	//작은수를 앞에 놓기위한 함수.
	void Sort()
	{
		if (f_set[0] > f_set[1])
		{
			int tmp = f_set[0];
			f_set[0] = f_set[1];
			f_set[1] = tmp;
		}
	}
};

int main()
{
    //Get Case Number
    int cases;
    cin >> cases;
	vector<int> counts;
	counts.reserve(cases);

	while (cases--) {
		//학생수 & 친구쌍수 
		int n_students;
		cin >> n_students;
		int n_friends;
		cin >> n_friends;

		if (n_students % 2 != 0) {
			//짝을 지을 수 없는 케이스(홀수)
			continue;
		}

        list<BF> l_friends;

        //Init Friends
        for(int i=0;i<n_friends;i++){
            BF f;
            cin >> f.f_set[0];
            cin >> f.f_set[1];
			//친구 넘버 작은숫자부터 소팅
			f.Sort();
            l_friends.push_back(f);
        }

        //Sorting -> 내림차순, 0번째 얘로.
        l_friends.sort();


		vector<vector<int>> l_students;
		l_students.reserve(n_friends * n_friends);

		//학생 수만큼 vector 생성.
		vector<int> students;
		students.reserve(n_students);
		students.assign(n_students, 0);

		//처음 학생집어넣깅
		l_students.push_back(students);


		for (list<BF>::iterator iter = l_friends.begin(); iter != l_friends.end(); iter++) {
			int size = l_students.size();
			bool isAdded = false;
			for (int num = 0; num < size; num++)
			{
				if (!l_students[num][(*iter).f_set[0]]
					&& !l_students[num][(*iter).f_set[1]])
				{
					//기존애 남겨야되니 추가.
					vector<int> new_students;
					new_students.reserve(n_students);
					new_students.assign(n_students, 0);
					for (int n = 0; n < l_students[num].size(); n++)
					{
						if(l_students[num][n] == 1)
							new_students[n] = 1;
					}
					l_students.push_back(new_students);



					//둘다 친구가 없으면..
					l_students[num][(*iter).f_set[0]] = 1;
					l_students[num][(*iter).f_set[1]] = 1;

					isAdded = true;
				}
			}
			if (!isAdded)
			{
				//친구가 있으면
				//학생 수만큼 vector 생성.
				vector<int> new_students;
				new_students.reserve(n_students);
				new_students.assign(n_students, 0);


				new_students[(*iter).f_set[0]] = 1;
				new_students[(*iter).f_set[1]] = 1;

				l_students.push_back(new_students);
			}
		}

		int count = 0;

		for (vector<vector<int>>::iterator iter = l_students.begin(); iter != l_students.end(); iter++) {
			bool isWORK = true;
			for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it++) {
				if ((*it) == 0)
				{
					isWORK = false;
				}
			}
			if (isWORK) count++;
		}

		counts.push_back(count);
    }


	for (vector<int>::iterator it = counts.begin(); it != counts.end(); it++)
	{
		cout << *it << endl;
	}
}
