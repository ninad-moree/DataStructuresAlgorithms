/*
    Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

    Example 1:
    Input: num1 = "2", num2 = "3"
    Output: "6"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> result(n1 + n2, 0); 

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int sum = result[i + j + 1] + product;

                result[i + j + 1] = sum % 10; 
                result[i + j] += sum / 10;    
            }
        }

        string ans;
        int i = 0;

        while (i < result.size() && result[i] == 0)
            i++;
        
        while (i < result.size()) {
            ans.push_back(result[i] + '0');
            i++;
        }

        if (ans.empty()) 
            return "0";

        return ans;
    }
};
