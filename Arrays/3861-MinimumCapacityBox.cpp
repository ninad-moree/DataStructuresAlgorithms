/*
    You are given an integer array capacity, where capacity[i] represents the capacity of the ith box, and an integer itemSize representing the size of an item. The ith box can
    store the item if capacity[i] >= itemSize. Return an integer denoting the index of the box with the minimum capacity that can store the item. If multiple such boxes exist, 
    return the smallest index. If no box can store the item, return -1.

    Example 1:
    Input: capacity = [1,5,3,7], itemSize = 3
    Output: 2
    Explanation: The box at index 2 has a capacity of 3, which is the minimum capacity that can store the item. Thus, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = INT_MAX;
        int mini = INT_MAX;

        for(int i=0; i<capacity.size(); i++) {
            int cap = capacity[i];

            if(cap >= itemSize && mini > cap) {
                mini = cap;
                ans = i;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};