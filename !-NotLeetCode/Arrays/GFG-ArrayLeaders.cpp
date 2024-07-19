/*
    Given an array arr of n positive integers, your task is to find all the leaders in the array. An element of the array is considered a 
    leader if it is greater than all the elements on its right side or if it is equal to the maximum element on its right side. The rightmost 
    element is always a leader.
    Examples

    Input: n = 6, arr[] = {16,17,4,3,5,2}
    Output: 17 5 2
    Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> ans;
        
        int maxi = arr[n-1];
        ans.push_back(maxi);
        
        for(int i=n-2; i>=0; i--) {
            if(arr[i] >= maxi) {
                maxi = arr[i];
                ans.push_back(maxi);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};