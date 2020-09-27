#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
using namespace std;
bool check_brute_force(const vector<int>& elements)
{
	for (size_t i = 0; i < elements.size(); i++)
	{
		for (size_t j = i+1; j < elements.size(); j++)
		{
			for (size_t k = j+1; k < elements.size(); k++)
			{
				if (elements[k] > elements[i] && elements[j] > elements[k])
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool check(const vector<int>& elements)
{
	vector<int> prefix_mins(elements.size());
	int current_min = elements[0];
	for (size_t i = 0; i < elements.size(); i++)
	{
		current_min = min(current_min, elements[i]);
		prefix_mins[i] = current_min;
	}

	int best_mid = INT_MIN;
	stack<int> rights;
	for (int i = elements.size()-1; i >= 0; i--)
	{
		int current_element = elements[i];
		while (!rights.empty() && rights.top() < prefix_mins[i])
			rights.pop();

		if (current_element > prefix_mins[i])
		{
			if (rights.empty() || current_element < rights.top())
			{
				rights.push(current_element);
				best_mid = INT_MIN;
			}
			else if (current_element > best_mid)
				best_mid = current_element;
		}
		else if (best_mid < current_element)
			best_mid = INT_MIN;
		
		if (best_mid != INT_MIN && !rights.empty())
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> elements(n);
	for (size_t i = 0; i < n; i++)
		cin >> elements[i];
	
	if (check(elements))
		cout << "da";
	else
		cout << "ne";
	return 0;
}