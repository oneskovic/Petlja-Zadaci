#include <iostream>
#include <vector>
#include <stack>

using namespace std;
#define ll long long
constexpr ll M = 1e9 + 7;

struct stack_element
{
	int element_value;
	int no_greater;
};

vector<int> find_prefixes(const vector<int>& elements, int start, int end, int step, bool can_equal)
{
	vector<int> prefixes(elements.size());
	stack<stack_element> prev_elements;

	for (int i = start; i != end; i+=step)
	{
		int current_element = elements[i];
		int no_greater = 0;
		while (!prev_elements.empty() &&
			((can_equal && current_element <= prev_elements.top().element_value) ||
			(!can_equal && current_element < prev_elements.top().element_value)))
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
	
	auto left_prefixes = find_prefixes(elements, 0, elements.size(), +1, true);
	auto right_prefixes = find_prefixes(elements, elements.size()-1, -1, -1,false);

	ll result = 0;
	for (size_t i = 0; i < n; i++)
	{
		ll element_sum = (ll)elements[i] * (left_prefixes[i] + 1) * (right_prefixes[i] + 1);
		element_sum %= M;
		result += element_sum;
		result %= M;
	}
	cout << result;
	return 0;
}