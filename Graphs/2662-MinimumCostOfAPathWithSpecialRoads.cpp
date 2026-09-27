/*
    You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. You are also given the array target where target
    = [targetX, targetY] represents your target position (targetX, targetY). The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1|
    + |y2 - y1|. There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] indicates that the ith special 
    road goes in one direction from (x1i, y1i) to (x2i, y2i) with a cost equal to costi. You can use each special road any number of times. Return the minimum cost required to 
    go from (startX, startY) to (targetX, targetY).

    Example 1:
    Input: start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
    Output: 5
    Explanation: (1,1) to (1,2) with a cost of |1 - 1| + |2 - 1| = 1. (1,2) to (3,3). Use specialRoads[0] with the cost 2.
    (3,3) to (3,4) with a cost of |3 - 3| + |4 - 3| = 1. (3,4) to (4,5). Use specialRoads[1] with the cost 1. So the total cost is 1 + 2 + 1 + 1 = 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int sx = start[0];
        int sy = start[1];
        int tx = target[0];
        int ty = target[1];

        if(sx == tx && sy == ty)
            return 0;

        map<pair<int, int>, int> cost; // {{x, y}, cost}

        cost[{sx, sy}] = 0;
        cost[{tx, ty}] = 1e9;

        // {cost, {x, y}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {sx, sy}});

        while(!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int c = pq.top().first;
            pq.pop();

            if(x == tx && y == ty)
                return c;

            // direct to target
            if(cost[{tx, ty}] > c + abs(x - tx) + abs(y - ty)) {
                cost[{tx, ty}] = c + abs(x - tx) + abs(y - ty);
                pq.push({cost[{tx, ty}], {tx, ty}});
            }

            // via special road
            for(auto i : specialRoads) {
                int x1 = i[0];
                int y1 = i[1];
                int x2 = i[2];
                int y2 = i[3];
                int co = i[4];

                int sc = c + abs(x - x1) + abs(y - y1) + co;

                if(cost.find({x2, y2}) == cost.end() || cost[{x2, y2}] > sc) {
                    cost[{x2, y2}] = sc;
                    pq.push({sc, {x2, y2}});
                }
            }
        }

        return -1;
    }
};