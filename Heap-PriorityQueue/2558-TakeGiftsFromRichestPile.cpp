/*
    You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:
    Choose the pile with the maximum number of gifts. If there is more than one pile with the maximum number of gifts, choose any.
    Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
    Return the number of gifts remaining after k seconds.

    Example 1:
    Input: gifts = [25,64,9,4,100], k = 4
    Output: 29
    Explanation: 
    The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;

        priority_queue<int> pq;

        for(auto g : gifts)
            pq.push(g);
        
        while(k > 0) {
            k--;
            int maxi = pq.top();
            pq.pop();

            maxi = sqrt(maxi);
            pq.push(maxi);
        }

        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};