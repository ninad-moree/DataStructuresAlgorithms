/*
    Alice and Bob are traveling to Rome for separate business meetings. You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from
    the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the 
    format "MM-DD", corresponding to the month and day of the date. Return the total number of days that Alice and Bob are in Rome together. You can assume that all dates occur 
    in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

    Example 1:
    Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
    Output: 3
    Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 
    18th, so the answer is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> daysBeforeMonth = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    int dayOfYear(string& date) {
        int month = (date[0] - '0') * 10 + (date[1] - '0');
        int day = (date[3] - '0') * 10 + (date[4] - '0');

        return daysBeforeMonth[month - 1] + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrive = max(dayOfYear(arriveAlice), dayOfYear(arriveBob));
        int leave = min(dayOfYear(leaveAlice), dayOfYear(leaveBob));

        return max(0, leave - arrive + 1);
    }
};