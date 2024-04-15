/*
    Given an array A of n positive numbers. The task is to find the first equilibrium point in an array. 
    Equilibrium point in an array is an index (or position) such that the sum of all elements before that 
    index is same as sum of elements after it.
    Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

    Example 1:
    Input: A[] = {1,3,5,2,2} 
    Output: 3 
    Explanation: equilibrium point is at position 3 as sum of elements before it (1+3) = sum of elements after it (2+2). 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        // Your code here
        long long totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += a[i];
    
        long long leftSum = 0;
    
        for (int i = 0; i < n; i++) {
            totalSum -= a[i];
    
            if (leftSum == totalSum)
                return i + 1; 
    
            leftSum += a[i];
        }
        
        return -1;
    }
};