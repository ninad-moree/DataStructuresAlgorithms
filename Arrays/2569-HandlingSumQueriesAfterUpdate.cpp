/*
    You are given two 0-indexed arrays nums1 and nums2 and a 2D array queries of queries. There are three types of queries:
    For a query of type 1, queries[i] = [1, l, r]. Flip the values from 0 to 1 and from 1 to 0 in nums1 from index l to index r. 
    Both l and r are 0-indexed.
    For a query of type 2, queries[i] = [2, p, 0]. For every index 0 <= i < n, set nums2[i] = nums2[i] + nums1[i] * p.
    For a query of type 3, queries[i] = [3, 0, 0]. Find the sum of the elements in nums2.
    Return an array containing all the answers to the third type queries.

    Example 1:
    Input: nums1 = [1,0,1], nums2 = [0,0,0], queries = [[1,1,1],[2,1,0],[3,0,0]]
    Output: [3]
    Explanation: After the first query nums1 becomes [1,1,1]. After the second query, nums2 becomes [1,1,1], so the answer to the third query is 3. Thus, [3] is returned.
*/

/* --------------- 72/77 Test Cases Passed --------------- */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<long long> ans;

        for(int i=0; i<queries.size(); i++) {
            int type = queries[i][0];
            if(type == 1) {
                int l = queries[i][1];
                int r = queries[i][2];

                for(int j=l; j<=r; j++) {
                    if(nums1[j] == 1) {
                        nums1[j] = 0;
                        continue;
                    }
                    if(nums1[j] == 0) {
                        nums1[j] = 1;
                        continue;
                    }
                }
            }
            if(type == 2) {
                int p = queries[i][1];

                for(int j=0; j<nums1.size(); j++) {
                    nums2[j] = nums2[j] + static_cast<long long>(nums1[j]*p);
                }
            }
            if(type == 3) {
                long long sum = 0;

                for(int j=0; j<nums2.size(); j++)
                    sum += nums2[j];
                
                ans.push_back(sum);
            }
        }

        return ans;
    }
};