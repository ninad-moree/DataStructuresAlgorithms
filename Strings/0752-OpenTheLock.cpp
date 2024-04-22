/*
    You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
    The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning 
    one wheel one slot. The lock initially starts at '0000', a string representing the state of the 4 wheels. You are given a list of deadends 
    dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
    Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the 
    lock, or -1 if it is impossible.

    Example 1:
    Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
    Output: 6
    Explanation: 
    A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
    Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
    because the wheels of the lock become stuck after the display becomes the dead end "0102".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        bool seen[10000] = {0};

        for(auto s : deadends)
            seen[stoi(s)] = 1;
        
        if(seen[0])
            return -1;
        
        queue<pair<int, string>> q;

        q.push({0, "0000"});
        seen[0] = 1;

        while(!q.empty()) {
            pair<int, string> front = q.front();
            q.pop();

            int turn = front.first;
            string s = front.second;

            if(s == target)
                return turn;

            for(int i=0; i<4; i++) {
                for(int j=-1; j<=1; j+=2) {
                    string temp = s;
                    char& move = temp[i];
                    move = (move - '0' + j + 10) % 10 + '0';
                    int x = stoi(temp);

                    if(!seen[x]) {
                        q.push({turn+1, temp});
                        seen[x] = 1;
                    }
                }
            }
        }

        return -1;
    }
};