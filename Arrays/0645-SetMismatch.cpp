/*
    You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, 
    due to some error, one of the numbers in s got duplicated to another number in the set, which results 
    in repetition of one number and loss of another number.
    You are given an integer array nums representing the data status of this set after the error.
    Find the number that occurs twice and the number that is missing and return them in the form of an array.

    Example 1:
    Input: nums = [1,2,2,4]
    Output: [2,3]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        vector<int> hash(n+1, 0);
        for(auto i : nums)
            hash[i]++;

        int rep = -1;
        int miss = -1;

        for(int i=0; i<hash.size(); i++) {
            if(hash[i] == 2)
                rep = i;
            if(hash[i] == 0)
                miss = i;
        }

        return {rep, miss};
    }   
};
