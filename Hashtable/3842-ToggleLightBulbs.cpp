/*
    You are given an array bulbs of integers between 1 and 100. There are 100 light bulbs numbered from 1 to 100. All of them are switched off initially. For each element 
    bulbs[i] in the array bulbs: If the bulbs[i]th light bulb is currently off, switch it on. Otherwise, switch it off. Return the list of integers denoting the light bulbs 
    that are on in the end, sorted in ascending order. If no bulb is on, return an empty list.

    Example 1:
    Input: bulbs = [10,30,20,10]
    Output: [20,30]
    Explanation: The bulbs[0] = 10th light bulb is currently off. We switch it on. The bulbs[1] = 30th light bulb is currently off. We switch it on. The bulbs[2] = 20th light 
    bulb is currently off. We switch it on. The bulbs[3] = 10th light bulb is currently on. We switch it off. In the end, the 20th and the 30th light bulbs are on.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> freq(101);

        for(int i=0; i<bulbs.size(); i++) {
            int b = bulbs[i];
            freq[b]++;
        }

        vector<int> ans;

        for(int i=1; i<101; i++) {
            if(freq[i] % 2 == 1)
                ans.push_back(i);
        }

        return ans;
    }
};