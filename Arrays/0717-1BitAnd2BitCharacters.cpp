/*
    We have two special characters: The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).
    Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.

    Example 1:
    Input: bits = [1,0,0]
    Output: true
    Explanation: The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        
        for(; i<bits.size()-1; i++) 
            i += (bits[i] == 1);

        return i == bits.size() - 1;
    }
};