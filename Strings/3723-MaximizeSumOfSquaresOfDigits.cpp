/*
    You are given two positive integers num and sum. A positive integer n is good if it satisfies both of the following: The number of digits in n is exactly num.
    The sum of digits in n is exactly sum. The score of a good integer n is the sum of the squares of digits in n. Return a string denoting the good integer n that achieves the
    maximum score. If there are multiple possible integers, return the maximum ​​​​​​​one. If no such integer exists, return an empty string.

    Example 1:
    Input: num = 2, sum = 3
    Output: "30"
    Explanation: There are 3 good integers: 12, 21, and 30. The score of 12 is 12 + 22 = 5. The score of 21 is 22 + 12 = 5. The score of 30 is 32 + 02 = 9.
    The maximum score is 9, which is achieved by the good integer 30. Therefore, the answer is "30".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 * num)
            return "";

        string ans = "";
        ans.resize(num, '0');
        int currSum = 0;

        for(int i=0; i<num; i++) {
            for(int d=9; d>=0; d--) {
                if(currSum + d <= sum) {
                    ans[i] = '0' + d;
                    currSum += d;
                    break;
                }
            }
        }

        if(currSum != sum)
            return "";

        return ans;
    }
};