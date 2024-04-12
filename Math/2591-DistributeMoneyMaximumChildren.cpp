/*
    You are given an integer money denoting the amount of money (in dollars) that you have and another integer children denoting the number of 
    children that you must distribute the money to. You have to distribute the money according to the following rules:
        All money must be distributed.
        Everyone must receive at least 1 dollar.
        Nobody receives 4 dollars.
    Return the maximum number of children who may receive exactly 8 dollars if you distribute the money according to the aforementioned rules. If there is no way to distribute the money, return -1.

    Example 1:
    Input: money = 20, children = 3
    Output: 1
    Explanation:
    - 8 dollars to the first child.
    - 9 dollars to the second child. 
    - 3 dollars to the third child.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children)
            return -1;

        if(money < children+7)
            return 0;
        
        int maxChildren = (money-children) / 7;
        float k = float(money) / (8*children);

        if(k > 1)
            return children -1;
        else if (k == 1)
            return children;
        else {
            if((money - 8 * (children-1)) == 4)
                return maxChildren -1;
            else
                return maxChildren;
        }
    }
};