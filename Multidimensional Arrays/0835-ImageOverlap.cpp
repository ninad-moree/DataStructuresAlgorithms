/*
    You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values. We translate one image however 
    we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by 
    counting the number of positions that have a 1 in both images. Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of 
    the matrix borders are erased. Return the largest possible overlap.

    Example 1:
    Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
    Output: 3
    Explanation: We translate img1 to right by 1 unit and down by 1 unit.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        vector<pair<int, int>> i1;
        vector<pair<int, int>> i2;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(img1[i][j] == 1)
                    i1.push_back({i, j});
                if(img2[i][j] == 1)
                    i2.push_back({i, j});
            }
        }

        unordered_map<int, int> freq;
        int ans = 0;

        for(auto i : i1) {
            for(auto j : i2) {
                int r1 = i.first;
                int c1 = i.second;

                int r2 = j.first;
                int c2 = j.second;

                int dr = r1 - r2;
                int dc = c1 - c2;

                int key = dr * 100 + dc;
                freq[key]++;

                ans = max(ans, freq[key]);
            }
        }

        return ans;
    }
};