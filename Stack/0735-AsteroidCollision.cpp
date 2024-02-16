/*
    We are given an array asteroids of integers representing asteroids in a row.
    For each asteroid, the absolute value represents its size, and the sign represents 
    its direction (positive meaning right, negative meaning left). Each asteroid moves at 
    the same speed.
    Find out the state of the asteroids after all collisions. If two asteroids meet, the 
    smaller one will explode. If both are the same size, both will explode. Two asteroids 
    moving in the same direction will never meet.

    Example 1:
    Input: asteroids = [5,10,-5]
    Output: [5,10]
    Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int a : asteroids) {
            if (a > 0) 
                s.push(a);
            else {
                while (!s.empty() && s.top() > 0 && abs(s.top()) < abs(a)) {
                    s.pop();
                }
                if (s.empty() || s.top() < 0) 
                    s.push(a);
                else if (abs(s.top()) == abs(a))
                    s.pop();
            }
        }

        vector<int> result(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            result[i] = s.top();
            s.pop();
        }

        return result;
    }
};