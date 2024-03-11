/*
    You are given an integer n that consists of exactly 3 digits.
    We call the number n fascinating if, after the following modification, the resulting number contains all the digits from 1 to 9 
    exactly once and does not contain any 0's:
    Concatenate n with the numbers 2 * n and 3 * n.
    Return true if n is fascinating, or false otherwise.
    Concatenating two numbers means joining them together. For example, the concatenation of 121 and 371 is 121371.

    Example 1:
    Input: n = 192
    Output: true
    Explanation: We concatenate the numbers n = 192 and 2 * n = 384 and 3 * n = 576. The resulting number is 192384576. This number 
    contains all the digits from 1 to 9 exactly once.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberToVector(int n) {
        vector<int> ans;

        while(n>0) {
            ans.push_back(n%10);
            n = n/10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    bool isFascinating(int n) {
        int n2 = 2*n;
        int n3 = 3*n;

        vector<int> v1 = numberToVector(n);
        vector<int> v2 = numberToVector(n2);
        vector<int> v3 = numberToVector(n3);

        for(int i=0; i<v2.size(); i++)
            v1.push_back(v2[i]);

        for(int i=0; i<v3.size(); i++)
            v1.push_back(v3[i]);

        sort(v1.begin(), v1.end());

        for(int i=0; i<v1.size()-1; i++) {
            if(v1[i]==0)
                return false;
            
            if(v1[i] == v1[i+1])
                return false;
        }

        return true;
    }
};