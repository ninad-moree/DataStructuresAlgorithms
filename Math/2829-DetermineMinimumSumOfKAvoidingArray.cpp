/*
    You are given two integers, n and k.
    An array of distinct positive integers is called a k-avoiding array if there does not exist 
    any pair of distinct elements that sum to k.
    Return the minimum possible sum of a k-avoiding array of length n.

    Example 1:
    Input: n = 5, k = 4
    Output: 18
    Explanation: Consider the k-avoiding array [1,2,4,5,6], which has a sum of 18.
    It can be proven that there is no k-avoiding array with a sum less than 18.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*--------------------- First Solution ---------------------*/
    int minimumSum(int n, int k) {
        int sum  = 0;
        int num = 1;
        unordered_map<int, int> mp;

        for(int i=0;i<n;i++) {
            while(mp.find(k-num) != mp.end())
                num++;
            mp[num]++;
            sum += num;
            num++;
        }

        return sum;
    }

    /*--------------------- Second Solution ---------------------*/
    bool search(vector<int>& arr, int k) {
        for(int i=0;i<arr.size();i++) {
            if(arr[i]==k) return true;
        }
        return false;
    }

    int minimumSum2(int n, int k) {
        vector<int> arr;
        for(int i=1;i<=n;i++) {
            arr.push_back(i);
        }
        int cnt = n+1;
        for(int i=0;i<n;i++) {
            while( search(arr, (k-arr[i])) && (k-arr[i] != arr[i])) {
                if(k-arr[i] > arr[i]) {
                    arr[k-arr[i]-1] = cnt;
                    cnt++;
                }
                else {
                    arr[i] = cnt;
                    cnt++;
                }
                
            }
        }

        int sum=0;
        for(int i=0;i<n;i++) {
            sum+=arr[i];
        }
        return sum;
    }
};