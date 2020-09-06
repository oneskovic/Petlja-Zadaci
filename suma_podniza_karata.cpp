#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> elements(n);
    // Used to save the running maximum in range [i,n)
    vector<int> current_maximums(n);

    for (size_t i = 0; i < n; i++)
        cin >> elements[i];

    int current_max = INT32_MIN;
    for (int i = n-1; i >= 0; i--)
    {
        current_max = max(current_max, elements[i]);
        current_maximums[i] = current_max;
    }

    // The sum equals the difference of the last and first elements
    // So try every possible first element (left) and for it pick the
    // Largest possible last element
    int max_solution = INT32_MIN;
    for (int i = 0; i < k; i++)
    {
        int best_right = current_maximums[n - 1 - (k - i)];
        int solution = best_right - elements[i];
        max_solution = max(solution, max_solution);
    }

    cout << max_solution;
    return 0;
}
