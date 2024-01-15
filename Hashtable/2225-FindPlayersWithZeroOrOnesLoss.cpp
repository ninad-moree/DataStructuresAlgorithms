/*
    You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player 
    loseri in a match.
    Return a list answer of size 2 where:
    answer[0] is a list of all players that have not lost any matches.
    answer[1] is a list of all players that have lost exactly one match.
    The values in the two lists should be returned in increasing order.
    
    Example 1:
    Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
    Output: [[1,2,10],[4,5,7,8]]
    Explanation:
    Players 1, 2, and 10 have not lost any matches.
    Players 4, 5, 7, and 8 each have lost one match.
    Players 3, 6, and 9 each have lost two matches.
    Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> winner;
        unordered_map<int, int> loser;

        for(int i=0;i<matches.size();i++) {
            winner[matches[i][0]]++;
            loser[matches[i][1]]++;
        }

        vector<vector<int>> ans;
        vector<int> win, lose;

        for(auto i : winner) {
            if(loser.find(i.first) == loser.end())
                win.push_back(i.first);
        }
        sort(win.begin(), win.end());

        ans.push_back(win);

        for(auto i : loser) {
            if(i.second == 1)
                lose.push_back(i.first);
        }
        sort(lose.begin(), lose.end());

        ans.push_back(lose);

        return ans;
    }
};