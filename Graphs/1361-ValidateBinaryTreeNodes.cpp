/*
    You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form 
    exactly one valid binary tree. If node i has no left child then leftChild[i] will equal -1, similarly for the right child. Note that the nodes have no values and that we 
    only use the node numbers in this problem.

    Example 1:
    Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n);

        // all nodes other than root have indegree == 1
        for(int i=0; i<n; i++) {
            if(leftChild[i] != -1) {
                indegree[leftChild[i]]++;

                if(indegree[leftChild[i]] > 1)
                    return false;
            }

            if(rightChild[i] != -1) {
                indegree[rightChild[i]]++;

                if(indegree[rightChild[i]] > 1)
                    return false;
            }
        }

        // root must have indegree == 0;
        int root = -1;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                if(root == -1)
                    root = i;
                else
                    return false;
            }
        }

        if(root == -1) 
            return false;

        queue<int> q;
        vector<int> vis(n);
        int cnt = 0;
        q.push(root);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            if(leftChild[node] != -1) {
                if(vis[leftChild[node]])
                    return false;
                q.push(leftChild[node]);
                vis[leftChild[node]] = 1;
            }

            if(rightChild[node] != -1) {
                if(vis[rightChild[node]])
                    return false;
                q.push(rightChild[node]);
                vis[rightChild[node]] = 1;
            }
        }

        return cnt == n;
    }
};