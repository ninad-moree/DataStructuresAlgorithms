/*
    You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length. In one edit you can take a 
    word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary. Return a
    list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.

    Example 1:
    Input: queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
    Output: ["word","note","wood"]
    Explanation:
    - Changing the 'r' in "word" to 'o' allows it to equal the dictionary word "wood". - Changing the 'n' to 'j' and the 't' to 'k' in "note" changes it to "joke".
    - It would take more than 2 edits for "ants" to equal a dictionary word. - "wood" can remain unchanged (0 edits) and match the corresponding dictionary word.
    Thus, we return ["word","note","wood"].
*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        for(int i=0;i<26;i++) 
            child[i] = NULL;
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string& str) {
        TrieNode* node = root;

        for(auto ch : str) {
            int idx = ch - 'a';

            if(!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }

        node->isEnd = true;
    }

    bool dfs(string& word, int i, TrieNode* node, int cnt) {
        if(cnt > 2)
            return false;
        if(!node)
            return false;

        if(i == word.size())
            return node->isEnd;

        int idx = word[i] - 'a';

        if(node->child[idx]) {
            if(dfs(word, i+1, node->child[idx], cnt))
                return true;
        }

        if(cnt < 2) {
            for(int ch=0; ch<26; ch++) {
                if(ch == idx)
                    continue;
                
                if(node->child[ch]) {
                    if(dfs(word, i+1, node->child[ch], cnt+1))
                        return true;
                }
            }
        }

        return false;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        for(auto i : dictionary)
            insert(i);

        vector<string> ans;
        for(auto word : queries) {
            if(dfs(word, 0, root, 0))
                ans.push_back(word);
        }

        return ans;
    }
};