/*
    On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.
    You are given an integer n, an array languages, and an array friendships where: There are n languages numbered 1 through n, languages[i] is the set of
    languages the i​​​​​​th​​​​ user knows, and friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship between the users u​​​​​​​​​​​i​​​​​ and vi. You can choose one language and teach it
    to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach. Note that friendships are not
    transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.

    Example 1:
    Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
    Output: 1
    Explanation: You can either teach user 1 the second language or user 2 the first language.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        vector<unordered_set<int>> knows(m + 1);
        
        for(int i=0; i<m; i++) {
            for(auto l : languages[i])
                knows[i+1].insert(l);
        }

        unordered_set<int> needteach;
        for(auto i : friendships) {
            int u = i[0];
            int v = i[1];
            bool can = false;

            for(auto l : knows[v]) {
                if(knows[u].count(l)) {
                    can = true;
                    break;
                }
            }

            if(!can) {
                needteach.insert(u);
                needteach.insert(v);
            }
        }

        if(needteach.empty())
            return 0;

        int ans = INT_MAX;

        for(int i=1; i<=n; i++) {
            int know = 0;
            for(auto j : needteach) {
                if(knows[j].count(i))
                    know++;
            }

            ans = min(ans, (int)needteach.size() - know);
        }

        return ans;
    }
};