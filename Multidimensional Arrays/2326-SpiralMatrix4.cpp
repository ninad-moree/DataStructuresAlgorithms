/*
    You are given two integers m and n, which represent the dimensions of a matrix. You are also given the head of a linked list of integers. Generate
    an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If 
    there are remaining empty spaces, fill them with -1. Return the generated matrix.

    Example 1:
    Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
    Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
    Explanation: The diagram above shows how the values are printed in the matrix.
    Note that the remaining spaces in the matrix are filled with -1.
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        ListNode* temp = head;

        int row = m;
        int col = n;

        int i = 0;
        int j = -1;
        int leftToRight = 1;

        while(row > 0 && col > 0) {
            for(int c=0; c<col; c++) {
                j += leftToRight;
                ans[i][j] = temp->val;
                temp = temp->next;
                if(temp == NULL)
                    break;
            }
            row--;

            if(temp == NULL)
                break;

            for(int r=0; r<row; r++) {
                i += leftToRight;
                ans[i][j] = temp->val;
                temp = temp->next;
                if(temp == NULL)
                    break;
            }
            col--;

            if(temp == NULL)
                break;

            leftToRight = leftToRight * (-1);
        }

        return ans;
    }
};