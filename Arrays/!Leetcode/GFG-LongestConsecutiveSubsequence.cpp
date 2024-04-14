/*
    Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the 
    subsequence are consecutive integers, the consecutive numbers can be in any order.
 
    Example 1:
    Input: a[] = {2,6,1,9,4,5,3}
    Output: 6
    Explanation:
    The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        if (N <= 1)
            return N;

        sort(arr, arr + N);
        int longest = 1, current = 1;
    
        for (int i = 1; i < N; ++i) {
            if (arr[i] != arr[i - 1]) {
                if (arr[i] == arr[i - 1] + 1)
                    current++;
                else {
                    longest = max(longest, current);
                    current = 1;
                }
            }
        }
        return max(longest, current);
    }
};