#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> element_count(2 * n + 1);

	// Count how many times each element appears (counting sort)
	for (size_t i = 0; i < n; i++)
	{
		int element; cin >> element;
		element_count[element]++;
	}

	// Print each element the number of times it appeared
	for (int element = 0; element < element_count.size(); element++)
	{
		for (size_t i = 0; i < element_count[element]; i++)
			cout << element << "\n";
	}

	return 0;
}