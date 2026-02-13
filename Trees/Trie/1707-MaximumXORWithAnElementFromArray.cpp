/*
    You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi]. The answer to the ith query is the maximum 
    bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in 
    nums are larger than mi, then the answer is -1. Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

    Example 1:
    Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
    Output: [3,3,7]
    Explanation:
    1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
    2) 1 XOR 2 = 3.
    3) 5 XOR 2 = 7.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[2];

    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* temp = root;

        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1; // ith bit is set or not;
            if(!temp->containsKey(bit)) 
                temp->put(bit, new Node());
            
            temp = temp->get(bit);
        }
    }

    int getMaxXOR(int num) {
        Node* temp = root;
        int maxi = 0;

        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;

            if(temp->containsKey(1 - bit)) {
                maxi = maxi | (1 << i); // turn on the bit (change it)
                temp = temp->get(1 - bit);
            } else
                temp = temp->get(bit);
        }

        return maxi;
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int, int>>> offlineQuery;
        for(int i=0; i<queries.size(); i++) 
            offlineQuery.push_back({queries[i][1], {queries[i][0], i}}); // {ai, {xi, i}}
        
        sort(offlineQuery.begin(), offlineQuery.end());

        int idx = 0;
        Trie trie;

        for(int i=0; i<offlineQuery.size(); i++) {
            int ai = offlineQuery[i].first;
            int xi = offlineQuery[i].second.first;
            int qIdx = offlineQuery[i].second.second;

            while(idx < nums.size() && nums[idx] <= ai) {
                trie.insert(nums[idx]);
                idx++;
            }

            if(idx == 0) 
                ans[qIdx] = -1;
            else
                ans[qIdx] = trie.getMaxXOR(xi);
        }

        return ans;
    }
};