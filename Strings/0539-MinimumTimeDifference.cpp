/*
    Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 
    Example 1:
    Input: timePoints = ["23:59","00:00"]
    Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> arr;

        for(int i=0; i<timePoints.size(); i++) {
            string time = timePoints[i];
            int hour = 0;
            hour += stoi(time.substr(0, 2));

            int mini = 0;
            mini += stoi(time.substr(3, 2));

            int totalMin = hour * 60 + mini;
            arr.push_back(totalMin);
        }

        sort(arr.begin(), arr.end());

        int ans = INT_MAX;

        for(int i=0; i<arr.size()-1; i++)
            ans = min(ans, abs(arr[i] - arr[i+1]));

        ans = min(ans, 1440 - (arr.back() - arr.front()));

        return ans;
    }
};