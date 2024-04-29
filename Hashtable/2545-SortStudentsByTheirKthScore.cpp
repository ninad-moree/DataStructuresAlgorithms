/*
    There is a class with m students and n exams. You are given a 0-indexed m x n integer matrix score, where each row represents one student 
    and score[i][j] denotes the score the ith student got in the jth exam. The matrix score contains distinct integers only.
    You are also given an integer k. Sort the students (i.e., the rows of the matrix) by their scores in the kth (0-indexed) exam from the 
    highest to the lowest. Return the matrix after sorting it.

    Example 1:
    Input: score = [[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2
    Output: [[7,5,11,2],[10,6,9,1],[4,8,3,15]]
    Explanation: In the above diagram, S denotes the student, while E denotes the exam.
    - The student with index 1 scored 11 in exam 2, which is the highest score, so they got first place.
    - The student with index 0 scored 9 in exam 2, which is the second highest score, so they got second place.
    - The student with index 2 scored 3 in exam 2, which is the lowest score, so they got third place.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        map<int, vector<int>> mp;

        for(int i=0; i<score.size(); i++)
            mp[score[i][k]] = score[i];

        vector<vector<int>> ans(score.size(), vector<int>(score[0].size(), 0));
        int j = score.size()-1;

        for(auto i : mp) {
            ans[j] = i.second;
            j--;
        }

        return ans;
    }
};