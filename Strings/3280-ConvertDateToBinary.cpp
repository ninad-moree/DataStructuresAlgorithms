/*
    You are given a string date representing a Gregorian calendar date in the yyyy-mm-dd format. date can be written in its binary representation obtained
    by converting year, month, and day to their binary representations without any leading zeroes and writing them down in year-month-day format. Return 
    the binary representation of date.

    Example 1:
    Input: date = "2080-02-29"
    Output: "100000100000-10-11101"
    Explanation:
    100000100000, 10, and 11101 are the binary representations of 2080, 02, and 29 respectively.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToBinary(int n) {
        string ans = "";
        while(n) {
            int r = n%2;
            n = n/2;
            ans += to_string(r);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string convertDateToBinary(string date) {
        vector<string> arr;
        stringstream ss(date);
        string token;

        while(getline(ss, token, '-')) 
            arr.push_back(token);

        string ans = "";
        
        ans += convertToBinary(stoi(arr[0]));
        ans += "-";
        ans += convertToBinary(stoi(arr[1]));
        ans += "-";
        ans += convertToBinary(stoi(arr[2]));

        return ans;
    }
};