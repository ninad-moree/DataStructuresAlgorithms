/*
    You are given a 0-indexed integer array nums. A pair of indices i, j where 0 <= i < j < nums.length is called beautiful if the 
    first digit of nums[i] and the last digit of nums[j] are coprime.
    Return the total number of beautiful pairs in nums.
    Two integers x and y are coprime if there is no integer greater than 1 that divides both of them. In other words, x and y are coprime 
    if gcd(x, y) == 1, where gcd(x, y) is the greatest common divisor of x and y.

    Example 1:
    Input: nums = [2,5,1,4]
    Output: 5
    Explanation: There are 5 beautiful pairs in nums:
    When i = 0 and j = 1: the first digit of nums[0] is 2, and the last digit of nums[1] is 5. We can confirm that 2 and 5 are coprime, since gcd(2,5) == 1.
    When i = 0 and j = 2: the first digit of nums[0] is 2, and the last digit of nums[2] is 1. Indeed, gcd(2,1) == 1.
    When i = 1 and j = 2: the first digit of nums[1] is 5, and the last digit of nums[2] is 1. Indeed, gcd(5,1) == 1.
    When i = 1 and j = 3: the first digit of nums[1] is 5, and the last digit of nums[3] is 4. Indeed, gcd(5,4) == 1.
    When i = 2 and j = 3: the first digit of nums[2] is 1, and the last digit of nums[3] is 4. Indeed, gcd(1,4) == 1.
    Thus, we return 5.
*/

#include<bits/stdc++.h>
#include<cmath>
using namespace std;

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;

        for(int i=0; i<nums.size()-1; i++) {
            int a = nums[i];
            int d1 = 0;
            while(a>0) {
                d1 = a%10;
                a = a/10;
            }
            for(int j=i+1; j<nums.size(); j++) {
                int b = nums[j];
                int d2 = b%10;

                if(__gcd(d1,d2) == 1)
                    ans++;
                // int a = nums[i];
                // int b = nums[j];

                // string c = to_string(a);
                // string d = to_string(b);
                
                // string e = "";
                // string f = "";
                // e += c[0];
                // f += d[d.size()-1];

                // int d1 = stoi(e);
                // int d2 = stoi(f);

                // if(gcd(d1, d2) == 1)
                //     ans++;
            }
        }

        return ans;
    }
};