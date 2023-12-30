/*
    Given an array Arr[] that contains N integers (may be positive, negative or zero). 
    Find the product of the maximum product subarray.

    Example 1:
    Input: Arr[] = {6, -3, -10, 0, 2}
    Output: 180
    Explanation: Subarray with maximum product is [6, -3, -10] which gives product as 180.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    if (n == 0) return 0;

        long long max_product = arr[0];
        long long min_product = arr[0];
        long long result = arr[0];

        for (int i = 1; i < n; ++i) {
            if (arr[i] < 0)
                swap(max_product, min_product);

            max_product = max((long long)arr[i], max_product * arr[i]);
            min_product = min((long long)arr[i], min_product * arr[i]);

            result = max(result, max_product);
        }

        return result;
	}
};