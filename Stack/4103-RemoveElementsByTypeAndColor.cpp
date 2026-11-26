/*
    You are given three integer arrays types, colors, and groupSize, where types and colors have length n, and groupSize has length m. types[i] represents the type of the 
    element at index i. colors[i] represents the color of the element at index i. groupSize[t] represents the required number of elements in a removable group of type t.
    In one operation, you may remove exactly groupSize[t] consecutive elements if all of them have type t and the same color. After each removal, the remaining elements become 
    adjacent again while maintaining their relative order. Return true if it is possible to remove all elements using a sequence of valid operations. Otherwise, return false.

    Example 1:
    Input: types = [0,1,1,0], colors = [5,3,3,5] , groupSize = [2,2]
    Output: true
    Explanation: First, remove the consecutive elements at indices 1 and 2. Both elements have type 1, color 3, and the group size is equal to groupSize[1] = 2.
    The remaining sequence is: types = [0, 0], colors = [5, 5] Now remove the two remaining elements. They have type 0, color 5, and the group size is equal to groupSize[0] = 2.
    All elements have been removed, so the answer is true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        int n = types.size();

        stack<vector<int>> st; // {type, color, cnt}

        for(int i=0; i<n; i++) {
            int t = types[i];
            int c = colors[i];

            if(!st.empty() && st.top()[0] == t && st.top()[1] == c) {
                int cnt = st.top()[2];
                st.pop();
                st.push({t, c, cnt + 1});
            } else
                st.push({t, c, 1});

            if(st.top()[2] == groupSize[t])
                st.pop();
        }

        return st.empty();
    }
};