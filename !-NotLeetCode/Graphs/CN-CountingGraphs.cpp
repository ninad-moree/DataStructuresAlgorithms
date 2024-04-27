/*
    Return the number of undirected graphs that can be formed using 'N' vertices, allowing for disconnected components within the graph. 
    Self-edges and multiple edges are not allowed.
    For Example:
    For N = 2,
    Count is 2.
    Consider the vertices to be ‘A’ and ‘B’.
    These are the possible 2 graphs.  
*/

#include<bits/stdc++.h>
using namespace std;

int countingGraphs(int N)
{
    // Write your code here.
    int p = N*(N-1) / 2;
    return pow(2, p);
}