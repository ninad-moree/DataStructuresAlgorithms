/*
    Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 

    Example 1:
    Input: n = 5, arr[] = {0, -1, 2, -3, 1}
    Output: 1
    Explanation: 0, -1 and 1 forms a triplet with sum equal to 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        if (n < 3) 
            return false; 
    
        sort(arr, arr + n);
    
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            int current = arr[i];
    
            while (left < right) {
                int sum = current + arr[left] + arr[right];
    
                if (sum == 0)
                    return true;
                else if (sum < 0)
                    left++;
                else
                    right--;
            }
        }
    
        return false;
    }
};