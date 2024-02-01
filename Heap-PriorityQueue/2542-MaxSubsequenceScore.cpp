/*
    You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. 
    You must choose a subsequence of indices from nums1 of length k.
    For chosen indices i0, i1, ..., ik - 1, your score is defined as:
    The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
    It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
    Return the maximum possible score.

    Example 1:
    Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
    Output: 12
    Explanation: 
    The four possible subsequence scores are:
    - We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
    - We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
    - We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
    - We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
    Therefore, we return the max score, which is 12.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> req;

        int n=nums1.size();
        for(int i=0 ; i<n ; i++){
            req.push_back({nums2[i],nums1[i]});
        }

        sort(req.begin(),req.end());
        reverse(req.begin(),req.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum=0;
        for(int i=0 ; i<k-1 ; i++){
            pq.push(req[i].second);
            sum+=req[i].second;
        }

        long long ans=0;
        for(int i=k-1 ; i<n ; i++){
            ans=max(ans,(long long)(sum+req[i].second)*req[i].first);
            if(pq.size() && pq.top()<req[i].second){
                sum-=pq.top();
                sum+=req[i].second;
                pq.pop();
                pq.push(req[i].second);
            }
        }
        
        return ans ;
    }
};