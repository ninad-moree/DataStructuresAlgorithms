/*
    You are keeping the scores for a baseball game with strange rules. At the beginning of the game, 
    you start with an empty record.
    You are given a list of strings operations, where operations[i] is the ith operation you must apply 
    to the record and is one of the following:
    An integer x.
        Record a new score of x.
    '+'.
        Record a new score that is the sum of the previous two scores.
    'D'.
        Record a new score that is the double of the previous score.
    'C'.
        Invalidate the previous score, removing it from the record.
    Return the sum of all the scores on the record after applying all the operations.

    Input: ops = ["5","2","C","D","+"]
    Output: 30
    Explanation:
        "5" - Add 5 to the record, record is now [5].
        "2" - Add 2 to the record, record is now [5, 2].
        "C" - Invalidate and remove the previous score, record is now [5].
        "D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
        "+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
        The total sum is 5 + 10 + 15 = 30.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> records;
        for(int i=0;i<operations.size();i++) {
            if(operations[i] == "C")
                records.pop_back();
            else if (operations[i] == "+")
                records.push_back(records[records.size()-1] + records[records.size()-2]);
            else if (operations[i] == "D")
                records.push_back(records[records.size()-1] * 2);
            else 
                records.push_back(stoi(operations[i]));
        }
        int ans = 0;
        for(int i=0;i<records.size();i++)
            ans += records[i];
        return ans;
    }
};