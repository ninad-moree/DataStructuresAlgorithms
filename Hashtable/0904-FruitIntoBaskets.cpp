/*
    You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits 
    where fruits[i] is the type of fruit the ith tree produces. You want to collect as much fruit as possible. However, the owner has some strict 
    rules that you must follow: You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of 
    fruit each basket can hold. Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) 
    while moving to the right. The picked fruits must fit in one of your baskets. Once you reach a tree with fruit that cannot fit in your baskets, 
    you must stop. Given the integer array fruits, return the maximum number of fruits you can pick.

    Example 1:
    Input: fruits = [1,2,1]
    Output: 3
    Explanation: We can pick from all 3 trees.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        unordered_map<int, int> mp;

        int j=0;

        for(int i=0; i<fruits.size(); i++) {
            if(mp.size() < 2 || mp.find(fruits[i]) != mp.end())
                mp[fruits[i]]++;
            else {
                while(mp.size() != 1) {
                    mp[fruits[j]]--;
                    if(mp[fruits[j]] == 0)
                        mp.erase(fruits[j]);
                    j++;
                }

                mp[fruits[i]]++;
            }

            int sum = 0;

            for(auto i : mp)
                sum += i.second;
                
            ans = max(ans, sum);
        }

        return ans;
    }
};