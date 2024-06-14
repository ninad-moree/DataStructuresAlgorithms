/*
    Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
    Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 
    should be placed at the end of arr1 in ascending order.

    Example 1:
    Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
    Output: [2,2,2,1,4,3,3,9,6,7,19]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;

        for(int i=0; i<arr2.size(); i++)
            mp[arr2[i]] = i;

        
        sort(arr1.begin(), arr1.end(), [&mp](int a, int b) {
            int idxA = mp.count(a) ? mp[a] : -1;
            int idxB = mp.count(b) ? mp[b] : -1;

            if(idxA == -1 && idxB == -1)
                return a<b;
            
            if(idxA >=0 && idxB >=0)
                return idxA < idxB;

            if(idxA >=0)
                return true;
            if(idxB >=0)
                return false;
            
            return false;
        });

        return arr1;
    }
};