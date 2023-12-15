/*
    You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. 
    Return the destination city, that is, the city without any path outgoing to another city.
    It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> source;
        vector<string> desti;
        for(int i=0;i<paths.size();i++) {
            source.insert(paths[i][0]);
            desti.push_back(paths[i][1]);
        }
        for (string city : desti) {
            if (source.find(city) == source.end()) {
                return city; 
            }
        }
        return "";
    }
};