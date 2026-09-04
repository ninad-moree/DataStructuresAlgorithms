/*
    You are given an integer n. Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.
    In standard formatting: A comma is inserted after every three digits from the right. Numbers with fewer than 4 digits contain no commas.

    Example 1:
    Input: n = 1002
    Output: 3
    Explanation: The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        if(n <= 999)
            return 0;

        long long ans = 0;

        long long start = 1000;
        long long commas = 1;

        while (start <= n) {
            long long end = min(n, start * 1000 - 1);

            ans += (end - start + 1) * commas;

            start *= 1000;
            commas++;
        }

        return ans;
    }
};