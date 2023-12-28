/*
    A string s is called happy if it satisfies the following conditions:
    s only contains the letters 'a', 'b', and 'c'.
    s does not contain any of "aaa", "bbb", or "ccc" as a substring.
    s contains at most a occurrences of the letter 'a'.
    s contains at most b occurrences of the letter 'b'.
    s contains at most c occurrences of the letter 'c'.
    Given three integers a, b, and c, return the longest possible happy string. 
    If there are multiple longest happy strings, return any of them. If there is no such string, 
    return the empty string "".

    A substring is a contiguous sequence of characters within a string.

    Example 1:
    Input: a = 1, b = 1, c = 7
    Output: "ccaccbcc"
    Explanation: "ccbccacc" would also be a correct answer.
*/

#include<bits/stdc++.h>
using namespace std;

#include <string>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";

        priority_queue<pair<int, char>> pq;
        if(a != 0)
            pq.push({a,'a'});
        if(b != 0)
            pq.push({b,'b'});
        if(c != 0)
            pq.push({c,'c'});

        while(!pq.empty()) {
            int cnt = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            if(res.size()>1 && (res[res.size()-1]==ch && res[res.size()-2]==ch)) {
                if(pq.empty())
                    break;

                int cnt2 = pq.top().first;
                char ch2 = pq.top().second;
                pq.pop();

                res += ch2;
                cnt2--;

                if(cnt2>0)
                    pq.push({cnt2, ch2});
            }
            else {
                res += ch;
                cnt--;
            }
            
            if(cnt>0)
                pq.push({cnt, ch});
        }

        return res;
    }
};
