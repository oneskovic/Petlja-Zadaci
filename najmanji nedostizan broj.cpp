#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<ll> numbers(n);
	for (size_t i = 0; i < n; i++)
		cin>>numbers[i];

	sort(numbers.begin(), numbers.end());

	bool found = false;
	ll number_to_find = 1; // Next natural number to find
	size_t index = 0; // Current position in the sorted numbers
	while (!found)
	{
		if (index >= numbers.size() || numbers[index] > number_to_find)
			found = true;
		else
			number_to_find += numbers[index++];
	}

	cout << number_to_find;
	return 0;
}