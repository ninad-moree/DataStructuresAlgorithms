/*
    Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
    For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).
    Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

    Example 1:
    Input: {([])}
    Output:  true
    Explanation: { ( [ ] ) }. Same colored brackets can form balanced pairs, with 0 number of unbalanced bracket.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        for(char c : x) {
            if(c == '(' || c == '[' || c == '{') 
                s.push(c);
            else {
                if(s.empty())
                    return false;
                else if(c == ')' && s.top() != '(')
                    return false;
                else if(c == ']' && s.top() != '[') 
                    return false;
                else if(c == '}' && s.top() != '{') 
                    return false;
                }
                s.pop();
            }
        }
        return s.empty();
    }
};