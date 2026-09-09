/*
    An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists). 
    Given an array arr[] of size N, Return the index of any one of its peak elements. 
    Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0. Also, 
    arr[] will be in ascending order before the peak element, and in descending order after that.

    Example 1:
    Input: arr[] = {1,2,3}
    Possible Answer: 2
    Generated Output: 1
    Explanation: index 2 is 3.
    It is the peak element as it is greater than its neighbour 2. If 2 is returned then the generated output will be 1 else 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
        int left = 0;
        int right = n - 1;
    
        while (left < right) {
            int mid = left + (right - left) / 2;
    
            if (arr[mid] > arr[mid + 1])
                right = mid;
            else 
                left = mid + 1;
            
        }

        return left;
    }
};