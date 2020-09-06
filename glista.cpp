#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

/// <summary>
/// Checks if there exist any series of successive natural numbers
/// of given length that sums to the given sum </summary>
bool check_length(ll length, ll sum)
{
	ll s = length * (length - 1) / 2;
	ll start_number = round((sum - s)*1.0 / length);
	// Check if solution is a whole number
	bool is_whole = ((length * start_number + s) == sum);
	return is_whole && (start_number > 0);
}

int main()
{
	ll n; cin >> n;
	int max_length = sqrt(4 * n + 1);
	int total_count = 0;
	for (int len = 2; len < max_length; len++)
	{
		if (check_length(len, n))
			total_count++;
	}
	
	cout << total_count;
	return 0;
}

