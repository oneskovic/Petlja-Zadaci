#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> elements(n);
	for (size_t i = 0; i < n; i++)
		cin>>elements[i];
	
	auto is_even = function<bool(int)>( [](const int& element) {
		return element % 2 == 0; });

	vector<int> odd_elements, even_elements;
	copy_if(elements.begin(), elements.end(), back_inserter(odd_elements), not1(is_even));
	copy_if(elements.begin(), elements.end(), back_inserter(even_elements), is_even);

	for (int element : even_elements)
		cout << element << " ";
	cout << "\n";
	for (int element : odd_elements)
		cout << element << " ";

	return 0;
}