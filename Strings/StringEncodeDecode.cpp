/*
    Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and 
    is decoded back to the original list of strings.
    Please implement encode and decode

    Example 1:
    Input: ["neet","code","love","you"]
    Output:["neet","code","love","you"]
    Explanation:
    One possible encode method is: "neet:;code:;love:;you"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string str = "";
        for (int i = 0; i < strs.size(); i++) {
            str += strs[i];
            if (i != strs.size() - 1)
                str += "###";
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string w = "";
        for (int i = 0; i < s.size(); i++) {
            if (s.substr(i, 3) != "###") {
                w += s[i];
            } else {
                ans.push_back(w);
                w = "";
                i += 2; // Skipping the delimiter
            }
        }
        if (!w.empty()) {
            ans.push_back(w); // Add the last word if it's not added
        }
        return ans;
    }
};
