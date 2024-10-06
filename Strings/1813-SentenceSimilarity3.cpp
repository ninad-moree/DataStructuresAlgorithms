/*
    You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated
    by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters. Two sentences s1 and s2
    are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences 
    become equal. Note that the inserted sentence must be separated from existing words by spaces.
    For example,
    s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
    s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
    Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

    Example 1:
    Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
    Output: true
    Explanation:
    sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<string> s1, vector<string> s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int left = 0, right = 0;

        while (left<n1 && left<n2 && s1[left] == s2[left]) 
            left++;

        while (right<n1 - left && right<n2 - left && s1[n1 - 1 - right] == s2[n2 - 1 - right]) 
            right++;

        return left + right >= min(n1, n2);
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1;
        vector<string> s2;

        stringstream ss1(sentence1);
        string t1;
        while(ss1 >> t1) 
            s1.push_back(t1);

        stringstream ss2(sentence2);
        string t2;
        while(ss2 >> t2)
            s2.push_back(t2);

        if (s1.size() > s2.size()) 
            return solve(s2, s1);

        return solve(s1, s2);
    }
};