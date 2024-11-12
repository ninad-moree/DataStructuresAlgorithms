/*
    You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively. You are also given a 
    0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to 
    queries[j]. If no such item exists, then the answer to this query is 0. Return an array answer of the same length as queries where answer[j] is the 
    answer to the jth query.

    Example 1:
    Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
    Output: [2,4,5,5,6,6]
    Explanation:
    - For queries[0]=1, [1,2] is the only item which has price <= 1. Hence, the answer for this query is 2.
    - For queries[1]=2, the items which can be considered are [1,2] and [2,4]. 
    The maximum beauty among them is 4.
    - For queries[2]=3 and queries[3]=4, the items which can be considered are [1,2], [3,2], [2,4], and [3,5].
    The maximum beauty among them is 5.
    - For queries[4]=5 and queries[5]=6, all items can be considered.
    Hence, the answer for them is the maximum beauty of all items, i.e., 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans(queries.size());

        sort(items.begin(), items.end());

        for (int i = 1; i < items.size(); ++i) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i) 
            sortedQueries.push_back({queries[i], i});
        sort(sortedQueries.begin(), sortedQueries.end());

        int j = 0;
        for (const auto& i : sortedQueries) {
            while (j < items.size() && items[j][0] <= i.first)
                j++;
            
        

            ans[i.second] = (j > 0) ? items[j - 1][1] : 0;
        }

        return ans;
    }
};