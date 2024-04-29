/*
    The problem is to find the rightmost bit of a non-negative number 'N' that is currently unset (i.e., has a value of 0) in its binary 
    representation and set it to 1. Return the number after setting the rightmost unset bit of 'N'. If there are no unset bits in N's binary 
    representation, then the number should remain unchanged.

    Example:
    N = 5
    Output: 7
    Explanation: The binary representation of 5 is 101. After setting the rightmost unset bit it becomes 111 which is 7.
*/

#include<bits/stdc++.h>
using namespace std;

int setBits(int N){
    // Write your code here.
    string bits = "";

    int temp = N;
    while(temp) {
        int i = temp%2;
        string str = to_string(i);
        bits += str[0];

        temp = temp/2;
    }

    reverse(bits.begin(), bits.end());

    int len = bits.size();

    int idx = len-1;
    while(idx >= 0) {
        if(bits[idx] == '0')
            break;
        idx--;
    }
    
    if(idx >= 0)
        N += pow(2, len-idx-1);

    return N;
}