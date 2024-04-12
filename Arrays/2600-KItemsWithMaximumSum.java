/* 
    There is a bag that consists of items, each item has a number 1, 0, or -1 written on it.
    You are given four non-negative integers numOnes, numZeros, numNegOnes, and k. The bag initially contains:
        numOnes items with 1s written on them.
        numZeroes items with 0s written on them.
        numNegOnes items with -1s written on them.
    We want to pick exactly k items among the available items. Return the maximum possible sum of numbers written on the items.

    Example 1:
    Input: numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
    Output: 2
*/

class Solution {
    public int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;

        for(int i=0; i<numOnes; i++) {
            if(k > 0) {
                ans++;
                k--;
            }
        }

        for(int i=0; i<numZeros; i++) {
            if(k > 0) {
                k--;
            }
        }

        for(int i=0; i<numNegOnes; i++) {
            if(k > 0) {
                ans--;
                k--;
            }
        }

        return ans;
    }
}