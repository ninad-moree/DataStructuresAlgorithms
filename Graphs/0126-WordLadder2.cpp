/*
    A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> 
    sk such that: 
    Every adjacent pair of words differs by a single letter. Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in 
    wordList. sk == endWord
    Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or
    an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

    Example 1:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
    Explanation: There are 2 shortest transformation sequences:
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"
    "hit" -> "hot" -> "lot" -> "log" -> "cog"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<vector<string>> q;
        q.push({beginWord});

        vector<string> level;
        level.push_back(beginWord);

        int lvl = 0;

        while(!q.empty()) {
            vector<string> words = q.front();
            q.pop();

            if(words.size() > lvl) {
                lvl++;
                for(auto i : level)
                    st.erase(i);
                level.clear();
            }

            string word = words.back();

            if(word == endWord) {
                if(ans.size() == 0)
                    ans.push_back(words);
                else if(ans[0].size() == words.size())
                    ans.push_back(words);
            }

            for(int i=0; i<word.size(); i++) {
                char ori = word[i];

                for(char c='a'; c<='z'; c++) {
                    word[i] = c;

                    if(st.find(word) != st.end()) {
                        words.push_back(word);
                        q.push(words);
                        level.push_back(word);
                        words.pop_back();
                    }
                }

                word[i] = ori;
            }
        }

        return ans;
    }
};