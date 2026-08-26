/*
    You are given two valid times startTime and endTime, each represented as a string in the format "HH:MM:SS". Return the number of seconds that have elapsed from startTime to
    endTime.

    Example 1:
    Input: startTime = "01:00:00", endTime = "01:00:25"
    Output: 25
    Explanation: endTime is 25 seconds ahead of startTime.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int convertHourToSecond(string hr) {
        int h = stoi(hr);
        h = h * 3600;
        return h;
    }

    int convertMinToSecond(string min) {
        int m = stoi(min);
        m = m * 60;
        return m;
    }

    int secondsBetweenTimes(string startTime, string endTime) {
        string hr1 = startTime.substr(0, 2);
        string min1 = startTime.substr(3, 2);
        string sec1 =  startTime.substr(6, 2);

        string hr2 = endTime.substr(0, 2);
        string min2 = endTime.substr(3, 2);
        string sec2 =  endTime.substr(6, 2);

        int h1 = convertHourToSecond(hr1);
        int m1 = convertMinToSecond(min1);
        int s1 = stoi(sec1);

        int h2 = convertHourToSecond(hr2);
        int m2 = convertMinToSecond(min2);
        int s2 = stoi(sec2);

        int totalS1 = h1 + m1 + s1;
        int totalS2 = h2 + m2 + s2;

        return totalS2 - totalS1;
    }
};