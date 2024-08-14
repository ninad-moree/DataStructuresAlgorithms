/*
    You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list 
    of intervals is pairwise disjoint and in sorted order. Return the intersection of these two interval lists.
    A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b. The intersection of two closed intervals is a set of real 
    numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].
    
    Example 1:
    Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
    Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;

        int l1 = firstList.size();
        int l2 = secondList.size();

        for(int i=0; i<l1; i++) {
            for(int j=0; j<l2; j++) {
                auto a = firstList[i];
                auto b = secondList[j];

                if(a[1] < b[0])
                    break;
                else if(b[1] < a[0]) 
                    continue;
                else
                    ans.push_back({max(a[0], b[0]), min(a[1], b[1])});
            }
        }

        return ans;
    }
};