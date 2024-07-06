/*
    There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the 
    person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction 
    changes, and people continue passing the pillow in the opposite direction. Given the two positive integers n and time, return the index 
    of the person holding the pillow after time seconds.
    
    Example 1:
    Input: n = 4, time = 5
    Output: 2
    Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
    Afer five seconds, the pillow is given to the 2nd person.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int idx = 1;
        bool forward = true;

        while (time > 0) {
            if (forward) {
                if (idx < n) 
                    idx++;
                else {
                    forward = false;
                    idx--;
                }
            } else {
                if (idx > 1)
                    idx--;
                else {
                    forward = true;
                    idx++;
                }
            }
            time--;
        }
        return idx;
    }
};