/*
    You are given a positive integer n.
    Let even denote the number of even indices in the binary representation of n (0-indexed) with value 1.
    Let odd denote the number of odd indices in the binary representation of n (0-indexed) with value 1.
    Return an integer array answer where answer = [even, odd].

    Example 1:
    Input: n = 17
    Output: [2,0]
    Explanation: The binary representation of 17 is 10001. It contains 1 on the 0th and 4th indices. There are 2 even and 0 odd indices.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> arr;
        while(n>0) {
            arr.push_back(n%2);
            n=n/2;
        }
        int even=0;
        int odd=0;
        
        for(int i=0;i<arr.size();i++) {
            if(arr[i]==1 && i%2==0)
                even++;
            if(arr[i]==1 && i%2!=0)
                odd++;
        }
        
        vector<int> brr(2);
        brr[0]=even;
        brr[1]=odd;
        return brr;
    }
};