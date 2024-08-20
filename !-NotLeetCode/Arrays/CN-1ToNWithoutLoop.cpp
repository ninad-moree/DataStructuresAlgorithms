/*
    You are given an integer ‘n’. Your task is to return an array containing integers from 1 to ‘n’ (in increasing order) without using loops.

    Example:
    Input: ‘n’ = 5
    Output: 1 2 3 4 5
    Explanation: An array containing integers from ‘1’ to ‘n’ is [1, 2, 3, 4, 5].
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> printNos(int x) {
    if(x == 1)  
        return {1};

    vector<int> ans = printNos(x-1);
    ans.push_back(x);
    return ans;
}