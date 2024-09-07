/*
    Given a binary tree root and a linked list with head as the first node. Return True if all the elements in the linked list starting from the head
    correspond to some downward path connected in the binary tree otherwise return False. In this context downward path means a path that starts at 
    some node and goes downwards.

    Example 1:
    Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
    Output: true
    Explanation: Nodes in blue form a subpath in the binary Tree.  
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool solve(ListNode* head, TreeNode* root) {
        if(!root)
            return false;
        
        if(head->val != root->val)
            return false;

        if(head->next == NULL)
            return true;

        bool left = false;
        bool right = false;

        if(root->left && head->next && root->left->val == head->next->val)
            left = solve(head->next, root->left);
        
        if(root->right && head->next && root->right->val == head->next->val)
            right = solve(head->next, root->right);

        return left || right;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)
            return false;
        
        if(root->val == head->val) {
            if(solve(head, root))
                return true;
        }

        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};