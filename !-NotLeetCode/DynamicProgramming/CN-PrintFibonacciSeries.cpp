/*
    Given an integer ‘n’, return first n Fibonacci numbers using a generator function.

    Example:
    Input: ‘n’ = 5
    Output: 0 1 1 2 3
    Explanation: First 5 Fibonacci numbers are: 0, 1, 1, 2, and 3.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> generateFibonacciNumbers(int n) {
    vector<int> ans(n);

    if(n==1)
        return {0};
    if(n == 2)
        return {0, 1};

    ans[0] = 0;
    ans[1] = 1;

    for(int i=2; i<n; i++) 
        ans[i] = ans[i-1] + ans[i-2];

    return ans;
}