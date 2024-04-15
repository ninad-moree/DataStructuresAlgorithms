/*
    You are given an array 'arr' of length 'N'. You are given 'Q' queries, and for each query, you are given an index(0-based indexing).
    Answer to each query is the number of the strictly greater elements to the right of the given index element.
    You must return an array 'answer' of length ’N’, where ‘answer[i]’ is the answer to the ‘ith’ query.

    Example:
    Input:
    arr = [5, 2, 10, 4], N=4, Q=2, query = [0, 1]
    Output:
    1 2
    Explanation: The element at index 0 is 5 for the first query. There is only one element greater than 5 towards the right, i.e., 10.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    // Write your code here.
    vector<int> ans(query.size());
    
    int k = 0;
    for(int i=0; i<query.size(); i++) {
        int idx = query[i];
        int cnt = 0;

        for(int j=idx+1; j<arr.size(); j++) {
            if(arr[j] > arr[idx])
                cnt++;
        }

        ans[k] = cnt;
        k++;
    }

    return ans;
}