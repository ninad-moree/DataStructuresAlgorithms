/*
    A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10. You are given a 2D integer array reservedSeats, where reservedSeats[i] = 
    [rowi, seati] means that seat seati in row rowi is already reserved. A four-person group must be assigned to four seats in the same row. The group can be seated in one of 
    the following seat blocks: seats 2, 3, 4, 5 | seats 4, 5, 6, 7 | seats 6, 7, 8, 9
    A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group. Return an integer denoting the maximum number of four-person 
    groups that can be assigned.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> rows;

        for (auto &seat : reservedSeats) 
            rows[seat[0]].insert(seat[1]);
        
        int ans = (n - rows.size()) * 2;

        for (auto i : rows) {
            int row = i.first;
            unordered_set<int> reserved = i.second;

            bool left = true;    // seats 2,3,4,5
            bool middle = true;  // seats 4,5,6,7
            bool right = true;   // seats 6,7,8,9

            for (int seat = 2; seat <= 5; seat++) {
                if (reserved.count(seat)) {
                    left = false;
                    break;
                }
            }

            for (int seat = 4; seat <= 7; seat++) {
                if (reserved.count(seat)) {
                    middle = false;
                    break;
                }
            }

            for (int seat = 6; seat <= 9; seat++) {
                if (reserved.count(seat)) {
                    right = false;
                    break;
                }
            }

            if (left && right) 
                ans += 2;
            else if (left || middle || right) 
                ans += 1;
        }

        return ans;
    }
};