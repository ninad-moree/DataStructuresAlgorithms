/*
    Given an array a of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than 
    once in the given array. Return the answer in ascending order. If no such element is found, return list containing [-1]. 
    Note: The extra space is only for the array to be returned. Try and perform all operations within the provided array. 

    Example 1:
    Input: N = 4 a[] = {0,3,1,2}
    Output: -1

    Example 2:
    Input: N = 5 a[] = {2,3,1,2,3}
    Output: 2 3 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        // code here
        vector<int> ans;
        sort(arr, arr + n);
        for(int i=0;i<n-1;i++) {
            if(arr[i] == arr[i+1]){
                if(ans.empty() || ans.back() != arr[i])
                    ans.push_back(arr[i]);
            }
        }
        if(ans.size() == 0)
            return {-1};
        return ans;
    }
};