/*
    You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's 
    in their binary representation and in case of two or more integers have the same number of 1's you have to 
    sort them in ascending order.
    Return the array after sorting it.

    Example 1:
    Input: arr = [0,1,2,3,4,5,6,7,8]
    Output: [0,1,2,4,8,3,5,6,7]
    Explantion: [0] is the only integer with 0 bits.
    [1,2,4,8] all have 1 bit.
    [3,5,6] have 2 bits.
    [7] has 3 bits.
    The sorted array by bits is [0,1,2,4,8,3,5,6,7]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSetBits(int num) {
        int count = 0;
        while (num > 0) {
            count += (num & 1);
            num >>= 1; 
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        map<int, vector<int>> mp;

        for (int num : arr) {
            int bits = countSetBits(num);
            mp[bits].push_back(num);
        }

        for (auto& pair : mp) 
            sort(pair.second.begin(), pair.second.end());
        

        vector<int> sortedArr;
        for (auto& pair : mp) {
            sortedArr.insert(sortedArr.end(), pair.second.begin(), pair.second.end());
        }

        return sortedArr;
    }
};