// Efficient C++ program to find maximum
// difference between frequency of any two
// elements such that element with greater
// frequency is also greater in value.
#include<bits/stdc++.h>
using namespace std;

// Return the maximum difference between
// frequencies of any two elements such that
// element with greater frequency is also
// greater in value.
int maxdiff(int arr[], int n)
{
	unordered_map<int, int> freq;

	int dist[n];

	// Finding the frequency of each element.
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (freq.find(arr[i]) == freq.end())
			dist[j++] = arr[i];

		freq[arr[i]]++;
	}

	// Sorting the distinct element
	sort(dist, dist + j);

	int min_freq = n+1;

	// Iterate through all sorted distinct elements.
	// For each distinct element, maintaining the
	// element with minimum frequency than that
	// element and also finding the maximum
	// frequency difference
	int ans = 0;
	for (int i=0; i<j; i++)
	{
		int cur_freq = freq[dist[i]];
		ans = max(ans, cur_freq - min_freq);
		min_freq = min(min_freq, cur_freq);
	}

	return ans;
}

// Driven Program
int main()
{
	int arr[] = { 3, 1, 3, 2, 3, 2 };
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << maxdiff(arr, n) << endl;
	return 0;
}
