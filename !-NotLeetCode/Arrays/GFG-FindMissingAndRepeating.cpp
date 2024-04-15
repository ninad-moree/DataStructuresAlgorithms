/*
    Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 
    'B' occurs twice in array. Find these two numbers.

    Example 1:
    Input: Arr[] = {2, 2}
    Output: 2 1
    Explanation: Repeating number is 2 and smallest positive missing number is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> result(2, -1);

        for (int i = 0; i < n; ++i) {
            if (arr[abs(arr[i]) - 1] < 0)
                result[0] = abs(arr[i]);
            else
                arr[abs(arr[i]) - 1] *= -1;
        }
    
        for (int i = 0; i < n; ++i) {
            if (arr[i] > 0) {
                result[1] = i + 1;
                break;
            }
        }
    
        return result;
    }
};