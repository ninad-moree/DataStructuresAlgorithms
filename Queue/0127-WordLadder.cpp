/*
    A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words 
    beginWord -> s1 -> s2 -> ... -> sk such that:
    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList. sk == endWord
    Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from 
    beginWord to endWord, or 0 if no such sequence exists.

    Example 1:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    Output: 5
    Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if(!st.count(endWord))
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            auto f = q.front();
            q.pop();

            string word = f.first;
            int level = f.second;

            for(int i=0; i<word.size(); i++) {
                string next = word;

                for(char j = 'a'; j<='z'; j++) {
                    next[i] = j;

                    if(next == word)
                        continue;

                    if(next == endWord)
                        return level + 1;

                    if(st.count(next)) {
                        q.push({next, level + 1});
                        st.erase(next);
                    }
                }
            }
        }

        return 0;
    }
};