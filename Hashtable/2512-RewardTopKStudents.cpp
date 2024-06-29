/*
    You are given two string arrays positive_feedback and negative_feedback, containing the words denoting positive and negative feedback, respectively.
    Note that no word is both positive and negative. Initially every student has 0 points. Each positive word in a feedback report increases the points 
    of a student by 3, whereas each negative word decreases the points by 1. You are given n feedback reports, represented by a 0-indexed string array 
    report and a 0-indexed integer array student_id, where student_id[i] represents the ID of the student who has received the feedback report report[i].
    The ID of each student is unique. Given an integer k, return the top k students after ranking them in non-increasing order by their points. In case 
    more than one student has the same points, the one with the lower ID ranks higher.

    Example 1:
    Input: positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], 
    report = ["this student is studious","the student is smart"], student_id = [1,2], k = 2
    Output: [1,2]
    Explanation: 
    Both the students have 1 positive feedback and 3 points but since student 1 has a lower ID he ranks higher.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        map<int, int> mp;
        set<string> pos, neg;

        for(int i=0; i<student_id.size(); i++) 
            mp[student_id[i]] = 0;

        for(auto p : positive_feedback)
            pos.insert(p);
        
        for(auto n : negative_feedback)
            neg.insert(n);
        
        for(int i=0; i<report.size(); i++) {
            string w = "";
            for(auto j : report[i]) {
                if(j == ' ') {
                    if(pos.count(w) >= 1)
                        mp[student_id[i]] += 3;
                    else if(neg.count(w) >= 1)
                        mp[student_id[i]] -= 1;
                    w = "";
                } else
                    w += j;
            }
            if(pos.count(w) >= 1)
                mp[student_id[i]] += 3;
            else if(neg.count(w) >= 1)
                mp[student_id[i]] -= 1;
        }

        vector<pair<int, int>> arr;
        for(auto i : mp) 
            arr.push_back({i.second, i.first});
        
        sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) {
            if(a.first > b.first) 
                return true;
            else if(a.first == b.first)
                return a.second < b.second;
            return false;
        });
        
        vector<int> ans;
        for(int i = 0; i < k && i < arr.size(); i++) 
            ans.push_back(arr[i].second);
        
        return ans;
    }
};