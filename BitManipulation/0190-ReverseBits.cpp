/*
    Reverse bits of a given 32 bits signed integer.

    Example 1:
    Input: n = 43261596
    Output: 964176192
    Explanation:
    Integer	Binary
    43261596	00000010100101000001111010011100
    964176192	00111001011110000010100101000000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0;   
    
        for(int i = 0; i < 32; i++) {
            result = result << 1;       
            result = result | (n & 1);        
            n = n >> 1;
        }
        
        return result;
    }
};