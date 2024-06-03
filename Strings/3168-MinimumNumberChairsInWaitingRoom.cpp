/*
    You are given a string s. Simulate events at each second i:
    If s[i] == 'E', a person enters the waiting room and takes one of the chairs in it.
    If s[i] == 'L', a person leaves the waiting room, freeing up a chair.
    Return the minimum number of chairs needed so that a chair is available for every person who enters the waiting room given that it is initially empty.

    Example 1:
    Input: s = "EEEEEEE"
    Output: 7
    Explanation:
    After each second, a person enters the waiting room and no person leaves it. Therefore, a minimum of 7 chairs is needed.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int curr = 0;
        int maxi = 0;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'E'){
                curr++;
                maxi = max(maxi, curr);
            } else 
                curr--;
        }
        
        return maxi;
    }
};