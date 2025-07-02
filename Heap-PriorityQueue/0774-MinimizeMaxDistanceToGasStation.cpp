/*
    On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length. Now, we 
    add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized. Return the smallest possible value of D.

    Example:
    Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
    Output: 0.500000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        vector<int> howMany(stations.size(), 0);
        priority_queue<pair<long double, int>> pq;

        for(int i=0; i<stations.size()-1; i++)
            pq.push({stations[i+1] - stations[i], i});

        for(int i=1; i<=k; i++) {
            auto top = pq.top();
            pq.pop();

            int sectionIndex = top.second;
            howMany[sectionIndex]++;

            long double diff = stations[sectionIndex + 1] - stations[sectionIndex];
            long double newLen = diff / (howMany[sectionIndex] + 1);

            pq.push({newLen, sectionIndex});
        }

        return pq.top().first;
    }
};