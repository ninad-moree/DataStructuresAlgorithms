/*
    Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
    Return any possible rearrangement of s or return "" if not possible.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        }
    };
    
    string reorganizeString(string s) {
        unordered_map<char, int> charFreq;
        for (char ch : s) {
            charFreq[ch]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> maxHeap;
        for (auto& entry : charFreq) {
            maxHeap.push(entry);
        }

        string result = "";
        while (maxHeap.size() > 1) {
            auto current = maxHeap.top();
            maxHeap.pop();

            auto next = maxHeap.top();
            maxHeap.pop();

            result += current.first;
            result += next.first;

            if (--current.second > 0) {
                maxHeap.push(current);
            }
            if (--next.second > 0) {
                maxHeap.push(next);
            }
        }

        if (!maxHeap.empty()) {
            if (maxHeap.top().second > 1) {
                return "";
            }
            result += maxHeap.top().first;
        }

        return result;
    }
};