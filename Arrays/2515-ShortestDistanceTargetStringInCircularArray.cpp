/*
    You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the 
    array's beginning. Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n],
    where n is the length of words. Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.
    Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.

    Example 1:
    Input: words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
    Output: 1
    Explanation: We start from index 1 and can reach "hello" by
    - moving 3 units to the right to reach index 4.
    - moving 2 units to the left to reach index 4.
    - moving 4 units to the right to reach index 0.
    - moving 1 unit to the left to reach index 0.
    The shortest distance to reach "hello" is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int i = startIndex;
        int j = startIndex;

        int left = 0;
        int right = 0;

        int ans = INT_MAX;
        int n = words.size();

        while(true) {
            if(words[i%n] == target)
                ans = min(ans, left);
        
            i++;
            left++;

            if(i%n == startIndex)
                break;
        }

        while(true) {
            if(words[i%n] == target)
                ans = min(ans, right);
            
            i--;
            right++;

            if(i%n == startIndex)
                break;
        }

        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};