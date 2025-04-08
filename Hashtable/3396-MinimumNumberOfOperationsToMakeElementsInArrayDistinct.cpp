/*
    You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following 
    operation any number of times: Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining 
    elements. Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in 
    the array distinct.

    Example 1:
    Input: nums = [1,2,3,4,2,3,3,5,7]
    Output: 2
    Explanation:
    In the first operation, the first 3 elements are removed, resulting in the array [4, 2, 3, 3, 5, 7]. In the second operation, the next 3 elements 
    are removed, resulting in the array [3, 5, 7], which has distinct elements. Therefore, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;

        for(int i=0; i<nums.size(); i+=3) {
            unordered_map<int, int> mp;

            for(int j=i; j<nums.size(); j++)
                mp[nums[j]]++;

            bool unique = true;
            for(auto j : mp) {
                if(j.second > 1){
                    unique = false;
                    break;
                }
            }

            if(unique)
                return ans;
            
            ans++;
        }

        return ans;
    }
};