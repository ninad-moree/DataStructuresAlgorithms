/*
    Given a positive integer num, split it into two non-negative integers num1 and num2 such that:
    The concatenation of num1 and num2 is a permutation of num.
    In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the number of occurrences of that digit in num.
    Return the minimum possible sum of num1 and num2.
    
    Example 1:
    Input: num = 4325
    Output: 59
    Explanation: We can split 4325 so that num1 is 24 and num2 is 35, giving a sum of 59. We can prove that 59 is indeed the minimal possible sum.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitNum(int num) {
        string str = to_string(num);
        sort(str.begin(), str.end());

        string n1 = "";
        string n2 = "";

        for(int i=0; i<str.size(); i++) {
            if(i%2 == 0)
                n1 += str[i];
            else
                n2 += str[i];
        }

        int num1 = stoi(n1);
        int num2 = stoi(n2);

        return num1 + num2;
    }
};