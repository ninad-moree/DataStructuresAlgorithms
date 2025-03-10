/*
    You are given three positive integers num1, num2, and num3. The key of num1, num2, and num3 is defined as a four-digit number such that:
    Initially, if any number has less than four digits, it is padded with leading zeros. The ith digit (1 <= i <= 4) of the key is generated by 
    taking the smallest digit among the ith digits of num1, num2, and num3. Return the key of the three numbers without leading zeros (if any).

    Example 1:
    Input: num1 = 1, num2 = 10, num3 = 1000
    Output: 0
    Explanation:
    On padding, num1 becomes "0001", num2 becomes "0010", and num3 remains "1000".
    The 1st digit of the key is min(0, 0, 1).
    The 2nd digit of the key is min(0, 0, 0).
    The 3rd digit of the key is min(0, 1, 0).
    The 4th digit of the key is min(1, 0, 0).
    Hence, the key is "0000", i.e. 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addingZeros(string& n) {
        if(n.size() < 4) {
            while(n.size() != 4)
                n = '0' + n;
        }

        return n;
    }

    int generateKey(int num1, int num2, int num3) {
        string n1 = to_string(num1);
        string n2 = to_string(num2);
        string n3 = to_string(num3);

        n1 = addingZeros(n1);
        n2 = addingZeros(n2);
        n3 = addingZeros(n3);

        string res = "";

        for(int i=0; i<4; i++) {
            string r1 = "";
            string r2 = "";
            string r3 = "";

            r1 += n1[i];
            r2 += n2[i];
            r3 += n3[i];

            int r11 = stoi(r1);
            int r22 = stoi(r2);
            int r33 = stoi(r3);

            int dig = min(r11, min(r22, r33));
            string num = to_string(dig);

            res += num;
        }

        int ans = stoi(res);
        return ans;
    }
};