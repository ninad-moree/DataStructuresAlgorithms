/*
    You have a 32-bit unsigned integer called 'num' and another integer called 'i'.
    You need to perform the following operations on the 'num' integer based on the value of 'i':
    1. Get the bit value at the "i"th position of "num".
    2. Set the bit at the "i"th position of "num".
    3. Clear the bit at the "i"th position of "num".
    We are starting bits from 1 instead of 0. (1-based)

    Example:
    N=25  i=3
    Output : 0 29 25
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> bitManipulation(int num, int i){
    // Write your code here.
    i = i-1;

    int mask = 1 << i;

    int bit = (num >> i) & 1;

    int setBit = num | mask;

    int clearedBit = num & ~mask;

    return {bit, setBit, clearedBit};
}