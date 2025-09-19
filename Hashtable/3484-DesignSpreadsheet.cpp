/*
    A spreadsheet is a grid with 26 columns (labeled from 'A' to 'Z') and a given number of rows. Each cell in the spreadsheet can hold an integer
    value between 0 and 105. Implement the Spreadsheet class:
    Spreadsheet(int rows) Initializes a spreadsheet with 26 columns (labeled 'A' to 'Z') and the specified number of rows. All cells are initially
    set to 0.
    void setCell(String cell, int value) Sets the value of the specified cell. The cell reference is provided in the format "AX" (e.g., "A1", 
    "B10"), where the letter represents the column (from 'A' to 'Z') and the number represents a 1-indexed row.
    void resetCell(String cell) Resets the specified cell to 0.
    int getValue(String formula) Evaluates a formula of the form "=X+Y", where X and Y are either cell references or non-negative integers, and 
    returns the computed sum. Note: If getValue references a cell that has not been explicitly set using setCell, its value is considered 0.

    Example 1:
    Input:
    ["Spreadsheet", "getValue", "setCell", "getValue", "setCell", "getValue", "resetCell", "getValue"]
    [[3], ["=5+7"], ["A1", 10], ["=A1+6"], ["B2", 15], ["=A1+B2"], ["A1"], ["=A1+B2"]]
    Output: [null, 12, null, 16, null, 25, null, 15]
*/

#include<bits/stdc++.h>
using namespace std;

class Spreadsheet {
public:
    unordered_map<string, int> mp;

    Spreadsheet(int rows) {}
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        for(int i=0; i<formula.size(); i++) {
            if(formula[i] == '+') {
                string s1 = formula.substr(0, i);
                string s2 = formula.substr(i+1);

                int n1 = s1[0] >= 'A' && s1[0] <= 'Z' ? mp[s1] : stoi(s1);
                int n2 = s2[0] >= 'A' && s1[0] <= 'Z' ? mp[s2] : stoi(s2);

                return n1 + n2;
            }
        }

        return 0;
    }
};