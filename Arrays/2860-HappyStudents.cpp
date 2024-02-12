/*
    You are given a 0-indexed integer array nums of length n where n is the total number of students in the class. 
    The class teacher tries to select a group of students so that all the students remain happy.
    The ith student will become happy if one of these two conditions is met:
    The student is selected and the total number of selected students is strictly greater than nums[i].
    The student is not selected and the total number of selected students is strictly less than nums[i].
    Return the number of ways to select a group of students so that everyone remains happy.

    Example 1:
    Input: nums = [1,1]
    Output: 2
    Explanation: 
    The two possible ways are:
    The class teacher selects no student.
    The class teacher selects both students to form the group. 
    If the class teacher selects just one student to form a group then the both students will not be happy. 
    Therefore, there are only two possible ways.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(vector<int>& nums) {
        int selected = 0;
        int ans = 0;

        sort(nums.begin(), nums.end());

        if(nums[0])
            ans++;

        for(int i=0;i<nums.size();i++) {
            selected++;

            if(nums[i] < selected) {
                if(i+1 < nums.size() && selected < nums[i+1])
                    ans++;
                if(i+1 == nums.size())
                    ans++;
            }
        }

        return ans;
    }
};