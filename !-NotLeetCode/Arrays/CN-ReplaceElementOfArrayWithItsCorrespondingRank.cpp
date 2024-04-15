/*
    Given an array of integers 'ARR’ of size ‘N’. Replace each element of this array with its corresponding rank and return the array.
    The rank of an element is an integer between 1 to ‘N’ inclusive that represents how large the element is in comparison to other elements 
    of the array. The following rules can also define the rank of an element:
    1. It is an integer starting from 1.
    2. The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
    3. It should be as small as possible.


    Example: 
    ARR = [4, 7, 2, 90]
    Here, 2 is the smallest element, followed by 4, 7, and 90. 
    Hence rank of element 2 is 1, element 4 is 2, element 7 is 3, and element 90 is 4.
    Hence we return [2, 3, 1, 4].
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int n) {
    // Write your code here.
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());

    unordered_map<int, int> ranks;
    int rank = 1;

    ranks[temp[0]] = rank;
    rank++;
    
    for(int i=1; i<arr.size(); i++) {
        if(temp[i] != temp[i-1]) {
          ranks[temp[i]] = rank;
          rank++;
        }

        if(temp[i] == temp[i-1]) {
            ranks[temp[i]] = ranks[temp[i-1]];
        }
    }

    vector<int> ans(arr.size());
    for(int i=0; i<arr.size(); i++) {
        ans[i] = ranks[arr[i]];
    }

    return ans;
}