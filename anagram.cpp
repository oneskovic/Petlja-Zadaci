
#	Status	Poeni	Vreme	Memorija
1	OK	1	0,00s	1,00MB
2	OK	1	0,00s	0,00MB
3	OK	1	0,02s	1,00MB
4	OK	1	0,00s	1,00MB
5	OK	1	0,00s	2,00MB
6	OK	1	0,00s	1,00MB
7	OK	1	0,00s	1,00MB
8	OK	1	0,00s	1,00MB
9	OK	1	0,00s	1,00MB
10	OK	1	0,00s	1,00MB
11	OK	1	0,00s	1,00MB
12	OK	1	0,00s	1,00MB
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
int main()
{
	string first, second;
	getline(cin, first);
	getline(cin, second);
	getline(cin, second);
	auto is_blank = [](char c)
	{
		return c == ' ';
	};

	first.erase(remove_if(first.begin(), first.end(), is_blank),first.end());
	second.erase(remove_if(second.begin(), second.end(), is_blank),second.end());
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	if (first == second)
		cout << "da";
	else
		cout << "ne";
	return 0;
}