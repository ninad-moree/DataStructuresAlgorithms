/*
    Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.
    More formally,
        G[i] for an element A[i] = an element A[j] such that 
        j is maximum possible AND 
        j < i AND
        A[j] < A[i]
    Elements for which no smaller element exist, consider next smaller element as -1.

    Input 1:  A = [4, 5, 2, 10, 8]
    Output 1: G = [-1, 4, -1, 2, 2]
    Explaination 1:
        index 1: No element less than 4 in left of 4, G[1] = -1
        index 2: A[1] is only element less than A[2], G[2] = A[1]
        index 3: No element less than 2 in left of 2, G[3] = -1
        index 4: A[3] is nearest element which is less than A[4], G[4] = A[3]
        index 4: A[3] is nearest element which is less than A[5], G[5] = A[3]
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    vector<int> ans (A.size(), -1);
    stack<int> st;
    
    
    for (int i = 0; i < A.size(); i++) {
        int curr = A[i];
        
        while(!st.empty() && st.top() >= curr) 
            st.pop();
        
        if(!st.empty())
            ans[i] = st.top();
        
        st.push(curr);
    }
    
    return ans;
}