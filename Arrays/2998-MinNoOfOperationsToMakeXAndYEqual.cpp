/*
    You are given two positive integers x and y.
    In one operation, you can do one of the four following operations:
    Divide x by 11 if x is a multiple of 11.
    Divide x by 5 if x is a multiple of 5.
    Decrement x by 1.
    Increment x by 1.
    Return the minimum number of operations required to make x and y equal.

    Example 1:
    Input: x = 26, y = 1
    Output: 3
    Explanation: We can make 26 equal to 1 by applying the following operations: 
    1. Decrement x by 1
    2. Divide x by 5
    3. Divide x by 5
    It can be shown that 3 is the minimum number of operations required to make 26 equal to 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<int> q;
        vector<int> visited(1e4 + 1, 0);
        q.push(x);

        if(x == y)
            return 0;

        int ans = 0;

        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                int front = q.front();
                q.pop();

                if(front>1e4+1 || front<=0)
                    continue;
                
                if(front == y)
                    return ans;
                
                if(front%11 == 0 && !visited[front/11]) {
                    visited[front/11] = 1;
                    q.push(front/11);
                }

                if(front%5 == 0 && !visited[front/5]) {
                    visited[front/5] = 1;
                    q.push(front/5);
                }

                if(front-1>=0 && !visited[front-1]) {
                    visited[front-1] = 1;
                    q.push(front-1);
                }

                if(front+1 <= 1e4 && !visited[front+1]) {
                    visited[front+1] = 1;
                    q.push(front+1);
                }
            }
            ans++;
        }
        return ans;
    }
};