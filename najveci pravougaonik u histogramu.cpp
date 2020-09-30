#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define ll long long

struct stack_element
{
	int element_value;
	int no_greater;
};

/// <summary>
/// For each element finds the number of elements that come before it and compare >= to the given element 
/// </summary>
vector<int> find_prefixes(const vector<int>& elements, int start, int end, int step)
{
	vector<int> prefixes(elements.size());
	stack<stack_element> prev_elements;

	for (int i = start; i != end; i += step)
	{
		int current_element = elements[i];
		int no_greater = 0;
		while (!prev_elements.empty() && current_element <= prev_elements.top().element_value)
		{
			no_greater += prev_elements.top().no_greater + 1;
			prev_elements.pop();
		}

		prev_elements.push({ current_element, no_greater });
		prefixes[i] = no_greater;
	}

	return prefixes;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;

	vector<int> elements(n);
	for (size_t i = 0; i < n; i++)
		cin >> elements[i];

	vector<int> left_prefixes = find_prefixes(elements, 0, elements.size(), 1);
	vector<int> right_prefixes = find_prefixes(elements, elements.size() - 1, -1, -1);

	ll max_area = 0;
	for (size_t i = 0; i < elements.size(); i++)
	{
		ll area = (ll)(left_prefixes[i] + right_prefixes[i] + 1) * elements[i];
		max_area = max(max_area, area);
	}
	cout << max_area;
	return 0;
}