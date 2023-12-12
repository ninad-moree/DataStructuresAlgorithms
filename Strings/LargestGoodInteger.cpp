/*
    You are given a string num representing a large integer. An integer is good if it meets the following conditions:
        It is a substring of num with length 3.
        It consists of only one unique digit.
    Return the maximum good integer as a string or an empty string "" if no such integer exists.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int nums = 0;
        bool isTrue = true;

        for(int i=0;i<num.size()-2;i++) {
            if(num[i]==num[i+1] && num[i+1]==num[i+2]) {
                nums = max(nums, num[i]-'0');
                isTrue = false;
            }
        }
        if(isTrue == false) {
            for(int i=0;i<3;i++)
                ans += to_string(nums);
        }
        return ans;
    }
};