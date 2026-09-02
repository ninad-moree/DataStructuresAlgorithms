/*
    You are given a string array events. Initially, score = 0 and counter = 0. Each element in events is one of the following:
    "0", "1", "2", "3", "4", "6": Add the value to the score. "W": Increase the counter by 1. No score is added. "WD": Add 1 to the total score. "NB": Add 1 to the total score.
    Process the array from left to right. Stop processing when either: All elements in events have been processed, or The counter becomes 10.
    Return an integer array [score, counter], where: score is the final total score. counter is the final counter value.

    Example 1:
    Input: events = ["1","4","W","6","WD"]
    Output: [12,1]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0;
        int cnt = 0;

        for(int i=0; i<events.size(); i++) {
            if(events[i] == "W")
                cnt++;
            else if(events[i] == "WD" || events[i] == "NB")
                score++;
            else
                score += stoi(events[i]);

            if(cnt == 10)
                break;
        }

        return {score, cnt};
    }
};