/*
    Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails 
    representing emails of the account. Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts.
    Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, 
    but all of their accounts definitely have the same name. After merging the accounts, return the accounts in the following format: the first element of each account is the name, 
    and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

    Example 1:
    Input: account = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
    Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
    Explanation: The first and second John's are the same person as they have the common email "johnsmith@mail.com". The third John and Mary are different people as none of their 
    email addresses are used by other accounts. We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
    ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector<int> size, parent;

    DisjointSet(int n) {
        size.resize(n+1, 0); // For both 0-based and 1-based indexing
        parent.resize(n+1);
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }

    int findUParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]); // Path Compression
    }

    void unionBySize(int u, int v) {
        int ultimateParentU = findUParent(u); // ultimate parent of u
        int ultimateParentV = findUParent(v); // ultimate parent of v

        if(ultimateParentU == ultimateParentV)
            return;

        if(size[ultimateParentU] < size[ultimateParentV]) {
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV] += size[ultimateParentU];
        } else {
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mapMailNode; // email, node (johnsmith@mail.com, John);
        DisjointSet ds(n);

        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                string email = accounts[i][j];

                if(mapMailNode.find(email) == mapMailNode.end())
                    mapMailNode[email] = i;
                else
                    ds.unionBySize(i, mapMailNode[email]);
            }
        }

        vector<vector<string>> mergedMail(n);

        for(auto i : mapMailNode) {
            string email = i.first;
            int node = ds.findUParent(i.second);

            mergedMail[node].push_back(email);
        }

        vector<vector<string>> ans;
        for(int i=0; i<mergedMail.size(); i++) {
            if(mergedMail[i].size() == 0)
                continue;
            
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto j : mergedMail[i])
                temp.push_back(j);
            
            ans.push_back(temp);
        }

        return ans;
    }
};