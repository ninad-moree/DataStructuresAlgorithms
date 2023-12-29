/*
    Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
    return the maximum number of points that lie on the same straight line.

    Example 1:
    Input: points = [[1,1],[2,2],[3,3]]
    Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct PairHash {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };

    int calculateGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return calculateGCD(b, a % b);
    }
    
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
            return n;

        int maxPointsOnLine = 2;
        for (int i = 0; i < n - 1; ++i) {
            unordered_map<pair<int, int>, int, PairHash> slopeCount;
            int duplicates = 1; 
            for (int j = i + 1; j < n; ++j) {
                int xDiff = points[j][0] - points[i][0];
                int yDiff = points[j][1] - points[i][1];

                if (xDiff == 0 && yDiff == 0) {
                    duplicates++;
                    continue;
                }

                int gcd = calculateGCD(xDiff, yDiff);
                slopeCount[{xDiff / gcd, yDiff / gcd}]++;
            }

            int localMax = duplicates; 
            for (const auto& pair : slopeCount) {
                localMax = std::max(localMax, pair.second + duplicates);
            }
            maxPointsOnLine = std::max(maxPointsOnLine, localMax);
        }

        return maxPointsOnLine;
    }
};