/*
    Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

    Example 1:
    Input: K = 6 arr[] = {1, 5, 7, 1}
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int, int> freqMap;
        int countPairs = 0;
    
        for (int i=0; i<n; i++) {
            int complement = k - arr[i];
    
            if (freqMap.find(complement) != freqMap.end())
                countPairs += freqMap[complement];
            
            freqMap[arr[i]]++;
        }
    
        return countPairs;
    }
};