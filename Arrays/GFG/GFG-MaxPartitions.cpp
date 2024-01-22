/*
    Given an array arr that is a permutation of [0.1,2....., arr.length()-1], we have to split the 
	array into some number of partitions such that when we sort those partitions separately and 
	concatenate them, the whole array is sorted. What is the maximum number of partitions we could make?
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int maxPartitions(vector<int> arr) {
        int n = arr.size();
        if(n<=1)
            return n;
        
        int maxEle = 0;
        int partitions = 0;

        for(int i=0; i<n; i++) {
            if(arr[i] > maxEle)
                maxEle = arr[i];
            if(i==maxEle)
                partitions++;
        }
        return partitions;
    }
};