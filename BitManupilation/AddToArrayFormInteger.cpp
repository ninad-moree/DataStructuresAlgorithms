/*
    The array-form of an integer num is an array representing its digits in left to right order.
    For example, for num = 1321, the array form is [1,3,2,1].
    Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

    Example 1:
    Input: num = [1,2,0,0], k = 34
    Output: [1,2,3,4]
    Explanation: 1200 + 34 = 1234
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        int sum; 
        int i=num.size()-1;

        while(k || carry) {
            sum = carry + k%10;
            k /= 10;

            if(i>=0) {
                sum += num[i];
                num[i] = sum%10;
                i--;
            }
            else
                num.insert(num.begin(), sum%10);

            carry = sum/10;
        }
        
        return num;
    }
};