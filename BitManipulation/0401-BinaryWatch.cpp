/*
    A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the 
    least significant bit on the right. Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the 
    watch could represent. You may return the answer in any order. The hour must not contain a leading zero. For example, "01:00" is not valid. It should be "1:00". The minute 
    must consist of two digits and may contain a leading zero. For example, "10:2" is not valid. It should be "10:02".
    
    Example 1:
    Input: turnedOn = 1
    Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSetBits(int n) {
        int cnt = 0;

        while(n > 0) {
            if(n & 1)
                cnt++;
            n = n >> 1;
        }

        return cnt;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int hr=0; hr<=11; hr++) {
            for(int min=0; min<=59; min++) {
                int totalBits = countSetBits(hr) + countSetBits(min);

                if(totalBits == turnedOn) {
                    string time = to_string(hr) + ":";

                    if(min < 10)
                        time += "0";
                    time += to_string(min);

                    ans.push_back(time);
                }
            }
        }

        return ans;
    }
};