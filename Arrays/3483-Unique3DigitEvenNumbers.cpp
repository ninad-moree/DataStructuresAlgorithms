/*
    You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits. Note: Each 
    copy of a digit can only be used once per number, and there may not be leading zeros.

    Example 1:
    Input: digits = [1,2,3,4]
    Output: 12
    Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed 
    because there is only 1 copy of the digit 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10);

        bool hasEven = false;

        for(auto i : digits) {
            freq[i] += freq[i] < 3;
            hasEven |= (i % 2 == 0);
        }

        if(!hasEven)
            return 0;

        int cnt = 0;

        for(int i=1; i<10; i++) {
            if(freq[i] == 0)
                continue;

            freq[i]--;

            for(int j=0; j<10; j++) {
                if(freq[j] == 0)
                    continue;

                freq[j]--;

                for(int k=0; k<10; k+=2) {
                    if(freq[k] == 0)
                        continue;

                    cnt++;
                }

                freq[j]++;
            }

            freq[i]++;
        }

        return cnt;
    }
};