/*
    You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:
    The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a 
    piece 'R' can move to the right only if there is a blank space directly to its right. The character '_' represents a blank space that can be 
    occupied by any of the 'L' or 'R' pieces. Return true if it is possible to obtain the string target by moving the pieces of the string start any 
    number of times. Otherwise, return false.

    Example 1:
    Input: start = "_L__R__R_", target = "L______RR"
    Output: true
    Explanation: We can obtain the string target from start by doing the following moves:
    - Move the first piece one step to the left, start becomes equal to "L___R__R_".
    - Move the last piece one step to the right, start becomes equal to "L___R___R".
    - Move the second piece three steps to the right, start becomes equal to "L______RR".
    Since it is possible to get the string target from start, we return true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        if(start ==  target)
            return true;

        int i = 0;
        int j = 0;
        int n = start.size();

        while(i<n || j<n) {
            while(i<n && start[i] == '_')
                i++;
            
            while(j<n && target[j] == '_')
                j++;

            if(i == n && j == n)
                break;
            if(start[i] != target[j]) 
                return false;
            
            if(start[i] == 'L') {
                if(i < j)
                    return false;
            }

            if(start[i] == 'R') {
                if(i > j)
                    return false;
            }

            i++;
            j++;
        }

        return i == n && j == n;
    }
};