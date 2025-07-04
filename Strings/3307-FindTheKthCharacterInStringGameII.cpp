/*
    Alice and Bob are playing a game. Initially, Alice has a string word = "a". You are given a positive integer k. You are also given an integer 
    array operations, where operations[i] represents the type of the ith operation. Now Bob will ask Alice to perform all operations in sequence:
    If operations[i] == 0, append a copy of word to itself.
    If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to 
    the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
    Return the value of the kth character in word after performing all the operations.

    Example 1:
    Input: k = 5, operations = [0,0,0]
    Output: "a"
    Explanation:
    Initially, word == "a". Alice performs the three operations as follows:
    Appends "a" to "a", word becomes "aa".
    Appends "aa" to "aa", word becomes "aaaa".
    Appends "aaaa" to "aaaa", word becomes "aaaaaaaa".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> lengths;
        long long len = 1; 
        
        for (int op : operations) {
            len *= 2;
            lengths.push_back(len);

            if (len >= k) 
                break; 
        }

        char c = 'a'; 

        for (int i = lengths.size() - 1; i >= 0; --i) {
            long long half = lengths[i] / 2;

            if (k > half) {
                k -= half;

                if (operations[i] == 1)
                    c = ((c - 'a' + 1) % 26) + 'a';
            }
        }

        return c;
    }
};