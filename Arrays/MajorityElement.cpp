/*
    Given an array A of N elements. Find the majority element in the array. A majority element in an array A of 
    size N is an element that appears strictly more than N/2 times in the array.
 
    Example 1:
    Input: A[] = {1,2,3} 
    Output: -1
    Explanation:
    Since, each element in {1,2,3} appears only once so there is no majority element.

    Example 2:
    Input: A[] = {3,1,3,3,2} 
    Output: 3
    Explanation:
    Since, 3 is present more than N/2 times, so it is the majority element.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // your code here
        int candidate = -1;
        int count = 0;      
        int n = size;

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                candidate = a[i];
                count = 1;
            } else if (a[i] == candidate)
                count++; 
            else
                count--; 
        }
    
        count = 0; 
        for (int i = 0; i < n; i++) {
            if (a[i] == candidate)
                count++;
        }
    
        if (count > n / 2)
            return candidate;
    
        return -1;
    }
};