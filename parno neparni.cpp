#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	vector<int> elements;
	int element;
	while (cin>>element)
		elements.push_back(element);
	

	auto is_even = function<bool(int)>([](const int& number) {
		return number % 2 == 0;
		});
	auto last_even_pos = find_if(elements.rbegin(), elements.rend(), is_even);
	auto first_odd_pos = find_if(elements.begin(), elements.end(), not1(is_even));
	if (first_odd_pos == last_even_pos.base())
		cout << "da";
	else
		cout << "ne";
	return 0;
}