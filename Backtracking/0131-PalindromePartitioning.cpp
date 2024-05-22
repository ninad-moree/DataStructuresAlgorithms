/*
    Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

    Example 1:
    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while(i < j) {
            if(s[i]!=s[j]) 
                return false;
            i++;
            j--;
        }
        
        return true;
    }

    void findPartitions(const string& s, int start, vector<string>& current, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                findPartitions(s, end + 1, current, result);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;
        findPartitions(s, 0, current, ans);
        return ans;
    }
};