/*
    Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, 
    and consists of groupSize consecutive cards.
    Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if 
    she can rearrange the cards, or false otherwise.
    
    Example 1:
    Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
    Output: true
    Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0)
            return false;

        map<int, int> mp;
        for(auto i : hand)
            mp[i]++;
        
        for(auto i = mp.begin(); i!=mp.end();) {
            int freq = i->second;
            if(freq > 0) {
                for(int j=0; j<groupSize;j++) {
                    if(mp[i->first + j] > 0)
                        mp[i->first + j]--;
                    else
                        return false;
                }
            } 
            else
                i++;
        }

        return true;
    }
};