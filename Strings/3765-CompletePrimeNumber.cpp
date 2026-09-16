/*
    You are given an integer num. A number num is called a Complete Prime Number if every prefix and every suffix of num is prime. Return true if num is a Complete Prime Number,
    otherwise return false. Note: A prefix of a number is formed by the first k digits of the number. A suffix of a number is formed by the last k digits of the number.
    Single-digit numbers are considered Complete Prime Numbers only if they are prime.

    Example 1:
    Input: num = 23
    Output: true
    Explanation: ​​​​​​​Prefixes of num = 23 are 2 and 23, both are prime. Suffixes of num = 23 are 3 and 23, both are prime. All prefixes and suffixes are prime, so 23 is a Complete 
    Prime Number and the answer is true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if(n < 2)
            return false;

        if(n == 2)
            return true;

        if(n % 2 == 0)
            return false;

        for(int i = 3; i * i <= n; i += 2) {
            if(n % i == 0)
                return false;
        }

        return true;
    }

    bool completePrime(int num) {
        bool isCom = true;

        // prefix
        string str = to_string(num);
        string s = "";

        for(int i=0; i<str.size(); i++) {
            s += str[i];
            int n = stoi(s);

            if(!isPrime(n)) {
                isCom = false;
                break;
            }
        }

        if(!isCom)
            return false;

        // suffix
        s = "";

        for(int i=str.size()-1; i>=0; i--) {
            s = str[i] + s;
            int n = stoi(s);

            if(!isPrime(n)) {
                isCom = false;
                break;
            }
        }

        return isCom;
    }
};