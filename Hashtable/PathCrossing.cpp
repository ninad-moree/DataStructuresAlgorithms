/*
    Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, 
    east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
    Return true if the path crosses itself at any point, that is, if at any time you are on a location you have 
    previously visited. Return false otherwise.

    Example 1:
    Input: path = "NES"
    Output: false 
    Explanation: Notice that the path doesn't cross any point more than once.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct PairHash {
        template <typename T, typename U>
        std::size_t operator()(const std::pair<T, U>& p) const {
            auto hashT = std::hash<T>{}(p.first);
            auto hashU = std::hash<U>{}(p.second);
            return hashT ^ hashU; // Combine hashes
        }
    };
    
    bool isPathCrossing(string path) {
        bool ans = false;
        pair<int, int> pos = {0, 0};
        unordered_map<pair<int, int>, bool, PairHash> mp; 
        mp[{0, 0}] = false;
        for(auto c : path) {
            if(c=='N') {
                pos.second += 1;
                if(mp.find(pos) == mp.end()) {
                    mp[pos] = false;
                }
                else {
                    ans = true;
                    break;
                }
            }
            else if(c=='S') {
                pos.second -= 1;
                if(mp.find(pos) == mp.end()) {
                    mp[pos] = false;
                }
                else {
                    ans = true;
                    break;
                }
            }
            else if(c=='E') {
                pos.first += 1;
                if(mp.find(pos) == mp.end()) {
                    mp[pos] = false;
                }
                else {
                    ans = true;
                    break;
                }
            }
            else if(c=='W') {
                pos.first -= 1;
                if(mp.find(pos) == mp.end()) {
                    mp[pos] = false;
                }
                else {
                    ans = true;
                    break;
                }
            }
        }
        return ans;
    }
};