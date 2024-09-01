/*
    There is an infinite 2D plane. You are given a positive integer k. You are also given a 2D array queries, which contains the following queries:
    queries[i] = [x, y]: Build an obstacle at coordinate (x, y) in the plane. It is guaranteed that there is no obstacle at this coordinate when this query is made.
    After each query, you need to find the distance of the kth nearest obstacle from the origin. Return an integer array results where results[i] 
    denotes the kth nearest obstacle after query i, or results[i] == -1 if there are less than k obstacles.
    The distance of an obstacle at coordinate (x, y) from the origin is given by |x| + |y|.

    Example 1:
    Input: queries = [[1,2],[3,4],[2,3],[-3,0]], k = 2
    Output: [-1,7,5,3]
    Explanation:
    Initially, there are 0 obstacles.
    After queries[0], there are less than 2 obstacles.
    After queries[1], there are obstacles at distances 3 and 7.
    After queries[2], there are obstacles at distances 3, 5, and 7.
    After queries[3], there are obstacles at distances 3, 3, 5, and 7.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> res(queries.size());

        priority_queue<int> pq;

        for(int i=0; i<queries.size(); i++) {
            int x = queries[i][0];
            int y = queries[i][1];

            x = abs(x);
            y = abs(y);

            pq.push(x+y);
            if(pq.size() > k)
                pq.pop();
            
            if(pq.size() < k)
                res[i] = -1;
            else
                res[i] = pq.top();
        }

        return res;
    }
};