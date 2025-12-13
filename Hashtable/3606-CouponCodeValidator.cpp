/*
    You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:
    code[i]: a string representing the coupon identifier. businessLine[i]: a string denoting the business category of the coupon.
    isActive[i]: a boolean indicating whether the coupon is currently active. A coupon is considered valid if all of the following conditions hold:
    code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_). 
    businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
    isActive[i] is true.
    Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in 
    lexicographical (ascending) order within each category.

    Example 1:
    Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]
    Output: ["PHARMA5","SAVE20"]
    Explanation: First coupon is valid. Second coupon has empty code (invalid). Third coupon is valid. Fourth coupon has special character @ (invalid).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidCode(const string& code) {
        if (code.empty())
            return false;

        for (char c : code) {
            if (!isalnum(c) && c != '_')
                return false;
        }
        
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> ans;
        vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};
        unordered_set<string> validBL(order.begin(), order.end());
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i])
                continue;
            if (!isValidCode(code[i])) 
                continue;
            if (!validBL.count(businessLine[i])) 
                continue;

            mp[businessLine[i]].push_back(code[i]);
        }

        for (auto &bl : order) {
            auto &v = mp[bl];
            sort(v.begin(), v.end());
            
            for (auto &c : v)
                ans.push_back(c);
        }

        return ans;
    }
};
