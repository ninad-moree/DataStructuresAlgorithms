/*
    You are given the root of a binary search tree and an array queries of size n consisting of positive integers.
    Find a 2D array answer of size n where answer[i] = [mini, maxi]:
    mini is the largest value in the tree that is smaller than or equal to queries[i]. If a such value does not exist, add -1 instead.
    maxi is the smallest value in the tree that is greater than or equal to queries[i]. If a such value does not exist, add -1 instead.
    Return the array answer.

    Example 1:
    Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries = [2,5,16]
    Output: [[2,2],[4,6],[15,-1]]
    Explanation: We answer the queries in the following way:
    - The largest number that is smaller or equal than 2 in the tree is 2, and the smallest number that is greater or equal than 2 is still 2. So the answer for the first query is [2,2].
    - The largest number that is smaller or equal than 5 in the tree is 4, and the smallest number that is greater or equal than 5 is 6. So the answer for the second query is [4,6].
    - The largest number that is smaller or equal than 16 in the tree is 15, and the smallest number that is greater or equal than 16 does not exist. So the answer for the third query is [15,-1].
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
    void inorder(TreeNode* root, vector<int>& ino) {
        if(root == NULL)
            return;
        
        inorder(root->left, ino);
        ino.push_back(root->val);
        inorder(root->right, ino);
    }

    int largestMin(vector<int>& arr, int target) {
        int ele = -1;
        int i=0;
        int j = arr.size()-1;

        while(i<=j) {
            int mid = i + (j-i)/2;

            if (arr[mid] <= target) {
                ele = arr[mid];
                i = mid + 1;
            } else 
                j = mid - 1;
        }

        return ele;
    }

    int smallestMax(vector<int>& arr, int target) {
        int ele = -1;
        int i=0;
        int j = arr.size()-1;

        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (arr[mid] >= target) {
                ele = arr[mid];
                j = mid - 1;
            } else 
                i = mid + 1;
        }

        return ele;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> ino;
        inorder(root, ino);

        vector<vector<int>> ans;

        for(auto i : queries) {
            int largeMin = largestMin(ino, i);
            int smallMax = smallestMax(ino, i);
            ans.push_back({largeMin, smallMax});
        }

        return ans;
    }
};