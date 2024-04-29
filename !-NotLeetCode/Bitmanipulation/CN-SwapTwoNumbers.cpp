/*
    You are given two numbers 'a' and 'b' as input.
    You must swap the values of 'a' and 'b'.

    For Example:
    Input: 
    'a' = 8, 'b' = 5
    Output:
    5 8
*/

#include<bits/stdc++.h>
using namespace std;

void swapNumber(int &a, int &b) {
	// Write your code here.
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}