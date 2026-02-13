/*
    Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

    Example 1:
    Input: nums = [3,10,5,25,2,8]
    Output: 28
    Explanation: The maximum result is 5 XOR 25 = 28.
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
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        
        Trie trie;
        for(auto i : nums) 
            trie.insert(i);
        
        int maxi = 0;

        for(auto i : nums) 
            maxi = max(maxi, trie.getMaxXOR(i));
        
        return maxi;
    }
};