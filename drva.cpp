#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

ll evaluate_solution(int solution, vector<ll>* lengths, ll target)
{
	ll sum = 0;
	for (size_t i = 0; i < lengths->size(); i++)
	{
		sum += max((ll)0, lengths->at(i) - solution);
		if (sum > target)
			break;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll target;
	cin >> n >> target;
	vector<ll> lengths(n);
	for (size_t i = 0; i < n; i++)
		cin >> lengths[i];

	int l = 0, r = *max_element(lengths.begin(), lengths.end());
	while (l <= r)
	{
		int mid = (l + r) / 2;
		ll solution = evaluate_solution(mid, &lengths, target);
		if (solution >= target)
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << r;
	return 0;
}