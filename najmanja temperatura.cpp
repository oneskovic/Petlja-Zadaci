#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> elements(n);
	for (size_t i = 0; i < n; i++)
		cin>>elements[i];

	cout << *min_element(elements.begin(), elements.end());
	return 0;
}