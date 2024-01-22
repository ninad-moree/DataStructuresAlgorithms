/*
    Alice and Bob have a different total number of candies. You are given two integer arrays aliceSizes and bobSizes where 
    aliceSizes[i] is the number of candies of the ith box of candy that Alice has and bobSizes[j] is the number of candies 
    of the jth box of candy that Bob has.
    Since they are friends, they would like to exchange one candy box each so that after the exchange, they both have the 
    same total amount of candy. The total amount of candy a person has is the sum of the number of candies in each box they have.
    Return an integer array answer where answer[0] is the number of candies in the box that Alice must exchange, and answer[1] 
    is the number of candies in the box that Bob must exchange. If there are multiple answers, you may return any one of them. 
    It is guaranteed that at least one answer exists.

    Example 1:
    Input: aliceSizes = [1,1], bobSizes = [2,2]
    Output: [1,2]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int alice = 0;
        int bob = 0;

        for(int i=0;i<aliceSizes.size();i++)
            alice += aliceSizes[i];
        
        for(int j=0;j<bobSizes.size();j++)
            bob += bobSizes[j];
        
        int mean = (alice + bob) /2;

        int diff = mean - alice;

        unordered_map<int, int> mp;
        for(int j=0;j<bobSizes.size();j++) 
            mp[bobSizes[j]] = j;
        

        vector<int> ans;
        for(int i = 0; i < aliceSizes.size(); i++) {
            int candy = aliceSizes[i] + diff;
            
            if(mp.find(candy) != mp.end())
                ans =  {aliceSizes[i], candy};
        }

        return ans;
    }
};