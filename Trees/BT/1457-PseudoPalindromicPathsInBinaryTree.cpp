/*
    Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic 
    if at least one permutation of the node values in the path is a palindrome.
    Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

    Example 1:
    Input: root = [2,3,1,3,1,null,1]
    Output: 2 
    Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: 
    the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-
    palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged 
    in [1,2,1] (palindrome).
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* node, unordered_map<int, int>& freqMap, int& count) {
        if (!node) 
            return;

        freqMap[node->val]++;

        if (!node->left && !node->right) {
            if (isPseudoPalindromic(freqMap)) 
                count++;
        }

        dfs(node->left, freqMap, count);
        dfs(node->right, freqMap, count);

        freqMap[node->val]--;
    }

    bool isPseudoPalindromic(const unordered_map<int, int>& freqMap) {
        int oddCount = 0;

        for (const auto& pair : freqMap) {
            if (pair.second % 2 != 0) 
                oddCount++;
        }
        return oddCount <= 1;
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0;
        unordered_map<int, int> freqMap; 
        dfs(root, freqMap, count);
        return count;
    }
};