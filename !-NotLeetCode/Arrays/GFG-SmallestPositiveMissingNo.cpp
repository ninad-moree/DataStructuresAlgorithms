/*
    You are given an array arr[] of N integers. The task is to find the smallest positive number missing from the array.

    Example 1:
    Input: arr[] = {1,2,3,4,5}
    Output: 6
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) {
        int ans = 1;
        sort(arr, arr+n);
        
        for(int i=0;i<n;i++) {
            if(arr[i]==ans)
                ans++;
        }
        return ans;
    }
};