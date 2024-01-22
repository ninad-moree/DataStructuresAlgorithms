/*
    Given an array of n names arr of candidates in an election, where each name is a string of lowercase characters. 
    A candidate name in the array represents a vote casted to the candidate. Print the name of the candidate that received 
    the maximum count of votes. If there is a draw between two candidates, then print lexicographically smaller name.
    
    Example 1:
    Input:
    n = 13
    arr[] = {john,johnny,jackie,johnny,john,jackie,jamie,jamie,john,johnny,jamie,johnny,john}
    Output: john 4
    Explanation: john has 4 votes casted for 
    him, but so does johny. john is 
    lexicographically smaller, so we print 
    john and the votes he received.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++)
            mp[arr[i]]++;

        string winner = "";
        int maxVotes = 0;

        for (const auto& pair : mp) {
            if (pair.second > maxVotes) {
                maxVotes = pair.second;
                winner = pair.first;
            } else if (pair.second == maxVotes && pair.first < winner)
                winner = pair.first;
        }

        return {winner, to_string(maxVotes)};
    }
};