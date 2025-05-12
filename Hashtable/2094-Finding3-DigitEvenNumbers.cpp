/*
    You are given an integer array digits, where each element is a digit. The array may contain duplicates. You need to find all the unique integers
    that follow the given requirements:
    The integer consists of the concatenation of three elements from digits in any arbitrary order.
    The integer does not have leading zeros. The integer is even.
    For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.
    Return a sorted array of the unique integers.

    Example 1:
    Input: digits = [2,1,3,0]
    Output: [102,120,130,132,210,230,302,310,312,320]
    Explanation: All the possible integers that follow the requirements are in the output array. 
    Notice that there are no odd integers or integers with leading zeros.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int digit : digits) 
            mp[digit]++;

        for (int i = 100; i <= 999; i += 2) {
            int n = i;
            int d1 = n / 100;       
            int d2 = (n / 10) % 10; 
            int d3 = n % 10;        

            if (d1 == 0) 
                continue;  

            unordered_map<int, int> temp = mp; 
            if (temp[d1] > 0 && temp[d2] > 0 && temp[d3] > 0) {
                temp[d1]--;
                temp[d2]--;
                temp[d3]--;

                if (temp[d1] >= 0 && temp[d2] >= 0 && temp[d3] >= 0) 
                    ans.push_back(i);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};