/*
    Given an array of integers temperatures represents the daily temperatures, 
    return an array answer such that answer[i] is the number of days you have to 
    wait after the ith day to get a warmer temperature. If there is no future day 
    for which this is possible, keep answer[i] == 0 instead.

    Example 1:
    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> stack;

        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                int prevIndex = stack.top();
                stack.pop();
                answer[prevIndex] = i - prevIndex;
            }
            stack.push(i);
        }

        return answer;
    }
};