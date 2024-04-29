/*
    For a given integer 'N', you have to return the number of set bits in the binary representation of the numbers from 1 to 'N'.
    In a binary number '1' is considered as a set bit and '0' as not set.

    Example:
    If 'N' is 4, then
    1 has a binary representation of 1
    2 has a binary representation of 10
    3 has a binary representation of 11
    4 has a binary representation of 100
*/

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int N) {
    //Write your code here
    int ans = 0;

    for(int i=1; i<=N; i++) {
        int dist = 0;

        for(int j=0; j<sizeof(int)*8; j++) {
            if( ((i >> j) & 1) != ((0 >> j) & 1) ) 
                dist++;
        }
        ans += dist;
    }

    return ans;
}