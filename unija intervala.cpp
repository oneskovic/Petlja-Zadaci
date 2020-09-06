#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

struct interval_point
{
	int position;
	bool is_end;
};
bool compare_interval_points(const interval_point& lhs, const interval_point& rhs)
{
	return lhs.position < rhs.position;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, position;
	cin >> n >> position;
	// We will represent each interval as 2 points
	vector<interval_point> interval_points(2 * n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> interval_points[i].position;
		interval_points[i].is_end = false;
	}
	for (size_t i = n; i < 2*n; i++)
	{
		cin >> interval_points[i].position;
		interval_points[i].is_end = true;
	}
	
	sort(interval_points.begin(), interval_points.end(), compare_interval_points);

	int no_intervals = 1; // The number of currently intersecting intervals
	int left_index = 0;
	while (true)
	{
		int right_index = left_index + 1;
		int length = interval_points[right_index].position - interval_points[left_index].position;
		if (interval_points[right_index].is_end)
			length++;
		if (interval_points[left_index].is_end)
			length--;
		
		int new_sum = length * no_intervals;
		if (new_sum >= position)
		{
			int i = position / no_intervals;
			if (interval_points[left_index].is_end)
				i++;
			
			cout << interval_points[left_index].position + i;
			break;
		}
		else
		{
			position -= new_sum;
			left_index++;
		}

		if (interval_points[right_index].is_end)
			no_intervals--;
		else
			no_intervals++;
	}

	return 0;
}