/*
    You are given an array people where people[i] is the weight of the ith person, 
    and an infinite number of boats where each boat can carry a maximum weight of limit. 
    Each boat carries at most two people at the same time, provided the sum of the weight 
    of those people is at most limit.
    Return the minimum number of boats to carry every given person.

    Example 2:
    Input: people = [3,2,2,1], limit = 3
    Output: 3
    Explanation: 3 boats (1, 2), (2) and (3)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int boats = 0;
        int left = 0, right = people.size() - 1;

        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            } else {
                right--;
            }
            boats++;
        }

        return boats;
    }
};