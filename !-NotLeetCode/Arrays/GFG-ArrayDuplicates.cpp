/*
    Given an array arr of size n which contains elements in range from 0 to n-1, you need to find all the elements occurring more than once in 
    the given array. Return the answer in ascending order. If no such element is found, return list containing [-1]. 
    Note: Try and perform all operations within the provided array. The extra (non-constant) ) space needs to be used only for the array to be 
    returned.

    Examples:

    Input: arr[] = {0,3,1,2}, n = 4
    Output: -1
    Explanation: There is no repeating element in the array. Therefore output is -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> duplicates(vector<long long> arr) {
        vector<int> ans;
        
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size()-1; i++) {
            if(arr[i] == arr[i+1])
                ans.push_back(arr[i]);
        }
        
        if(ans.size() == 0)
            return {-1};
            
        return ans;
    }
};