#include <iostream>
#include <algorithm>
#include <vector>
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
	// Find prefix minimums
	vector<int> prefix_mins(elements.size());
	int current_min = elements[0];
	for (size_t i = 0; i < elements.size(); i++)
	{
		current_min = min(current_min, elements[i]);
		prefix_mins[i] = current_min;
	}

	// Find a tuple (Left, Mid, Right) such that Left < Right < Mid
	// "Left" element can be found in O(1) using prefix minimums so the only thing left
	// is to find elements Mid and Right so that Mid > Right and both are smaller than the prefix min for Mid
	// To do this we will start from the last element and check if it can be the Mid element
	// The possible Right elements will be keept in a stack (rights) so that we can fall back on them if needed

	int mid = INT_MIN;
	stack<int> rights; // The rights stack will always be in decreasing order (when looking from the bottom up)
	for (int i = elements.size()-1; i >= 0; i--)
	{
		int current_element = elements[i];
		// Remove the right elements that no longer fit the criterium
		// This happens when we move "too much" to the left which leads to a bigger prefix min
		while (!rights.empty() && rights.top() <= prefix_mins[i])
			rights.pop();

		// The current element must be bigger than prefix min upto i to be either Mid or Right
		if (current_element > prefix_mins[i])
		{
			if (rights.empty() || current_element < rights.top())
			{
				// The element is smaller than all Right element candidates, just add it to the stack
				rights.push(current_element);
				// Reset the mid - as the current mid cant be used with the newly added right element
				mid = INT_MIN;
			}
			else
				mid = current_element;
		}
		
		// If the Mid element and a Right element exist a solution has been found
		if (mid != INT_MIN && !rights.empty())
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