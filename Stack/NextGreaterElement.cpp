/*
    Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element of the array 
    in order of their appearance in the array.
    Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
    If there does not exist next greater of current element, then next greater element for current element is -1. For example, next 
    greater of the last element is always -1.

    Example 1:
    Input: arr[] = [1 3 2 4]
    Output: 3 4 4 -1
    Explanation: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist, it is -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans(n, -1); 
        stack<int> s; 
    
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[i] > arr[s.top()]) {
                ans[s.top()] = arr[i]; 
                s.pop(); 
            }
            s.push(i);
        }
    
        return ans;
    }
};