#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
struct stack_element
{
	int element_value;
	bool was_used_in_segment;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	vector<int> elements(n);
	for (size_t i = 0; i < n; i++)
		cin >> elements[i];

	stack<stack_element> element_stack;
	long long total_count = 0;
	for (size_t i = 0; i < n; i++)
	{
		int current_element = elements[i];
		bool used_in_segment = false;
		while (!element_stack.empty() && current_element > element_stack.top().element_value)
		{
			total_count++;
			element_stack.pop();
		}
		if (!element_stack.empty() && current_element == element_stack.top().element_value &&
				!element_stack.top().was_used_in_segment)
		{
			total_count++;
			used_in_segment = true;
			element_stack.pop();
		}
		if (!element_stack.empty() && current_element < element_stack.top().element_value)
		{
			total_count++;
		}
		element_stack.push({ current_element,used_in_segment });
	}
	cout << total_count;
	return 0;
}