#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> elements(7);
	for (size_t i = 0; i < 7; i++)
		cin>>elements[i];
	
	cout << max_element(elements.begin(),elements.end()) - elements.begin() + 1;
	return 0;
}