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

class Solution {
public:
    int diff(string w1, string w2) {
        int n = w1.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            if(w1[i] != w2[i])
                ans++;
        }

        return ans;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(int i=0; i<queries.size(); i++) {
            string word1 = queries[i];

            for(int j=0; j<dictionary.size(); j++) {
                string word2 = dictionary[j];

                if(diff(word1, word2) <= 2) {
                    ans.push_back(word1);
                    break;
                }
            }
        }

        return ans;
    }
};