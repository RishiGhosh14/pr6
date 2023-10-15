// C++ program to get minimum cost to sort
// strings by reversal operation
#include <bits/stdc++.h>
using namespace std;

// Returns minimum cost for sorting arr[]
// using reverse operation. This function
// returns -1 if it is not possible to sort.
int minCost(string arr[], int cost[], int N)
{
	// dp[i][j] represents the minimum cost to
	// make first i strings sorted.
	// j = 1 means i'th string is reversed.
	// j = 0 means i'th string is not reversed.
	int dp[N][2];

	// initializing dp array for first string
	dp[0][0] = 0;
	dp[0][1] = cost[0];

	// getting array of reversed strings
	string revStr[N];
	for (int i = 0; i < N; i++)
	{
		revStr[i] = arr[i];
		reverse(revStr[i].begin(), revStr[i].end());
	}

	string curStr;
	int curCost;

	// looping for all strings
	for (int i = 1; i < N; i++)
	{
		// Looping twice, once for string and once
		// for reversed string
		for (int j = 0; j < 2; j++)
		{
			dp[i][j] = INT_MAX;

			// getting current string and current
			// cost according to j
			curStr = (j == 0) ? arr[i] : revStr[i];
			curCost = (j == 0) ? 0 : cost[i];

			// Update dp value only if current string
			// is lexicographically larger
			if (curStr >= arr[i - 1])
				dp[i][j] = min(dp[i][j], dp[i-1][0] + curCost);
			if (curStr >= revStr[i - 1])
				dp[i][j] = min(dp[i][j], dp[i-1][1] + curCost);
		}
	}

	// getting minimum from both entries of last index
	int res = min(dp[N-1][0], dp[N-1][1]);

	return (res == INT_MAX)? -1 : res;
}

// Driver code to test above methods
int main()
{
	string arr[] = {"aa", "ba", "ac"};
	int cost[] = {1, 3, 1};
	int N = sizeof(arr) / sizeof(arr[0]);

	int res = minCost(arr, cost, N);
	if (res == -1)
		cout << "Sorting not possible\n";
	else
		cout << "Minimum cost to sort strings is "
			<< res;
}
