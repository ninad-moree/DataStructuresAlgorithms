/*
    Given a positive integer n, find and return the longest distance between any two adjacent 1's in the binary representation of n. If there are no two adjacent 1's, return 0.
    Two 1's are adjacent if there are only 0's separating them (possibly no 0's). The distance between two 1's is the absolute difference between their bit positions. For 
    example, the two 1's in "1001" have a distance of 3.

    Example 1:
    Input: n = 22
    Output: 2
    Explanation: 22 in binary is "10110".
    The first adjacent pair of 1's is "10110" with a distance of 2.
    The second adjacent pair of 1's is "10110" with a distance of 1.
    The answer is the largest of these two distances, which is 2.
    Note that "10110" is not a valid pair since there is a 1 separating the two 1's underlined.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        string binary = "";
        while(n > 0) {
            int rem = n % 2;
            string re = to_string(rem);
            binary += re;

            n = n/2;
        }

        reverse(binary.begin(), binary.end());

        int i = 0;
        int j = i+1;
        int ans = 0;

        while(j < binary.size()) {
            if(binary[i] == '1' && binary[j] == '1') {
                ans = max(ans, j - i);
                i = j;
                j++;
            } else if(binary[i] == '1' && binary[j] == '0') {
                while(j < binary.size()) {
                    if(binary[j] == '1')
                        break;
                    j++;
                }
            } else if(binary[i] == '0') {
                while(i < binary.size()) {
                    if(binary[i] == '1') {
                        j = i+1;
                        break;
                    }
                    i++;
                }
            }
        }

        return ans;
    }
};