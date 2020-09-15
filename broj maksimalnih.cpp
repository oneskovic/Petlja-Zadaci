#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> elements(n);
	for (size_t i = 0; i < n; i++)
		cin >> elements[i];
	
	int max = *max_element(elements.begin(), elements.end());
	int count_max = count_if(elements.begin(), elements.end(), [max](const int& element) {
			return element == max;
		});
	cout << count_max;
	return 0;
}