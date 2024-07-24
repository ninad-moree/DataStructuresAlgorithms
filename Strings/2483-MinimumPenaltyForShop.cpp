/*
    You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':
    if the ith character is 'Y', it means that customers come at the ith hour whereas 'N' indicates that no customers come at the ith hour.
    If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:
    For every hour when the shop is open and no customers come, the penalty increases by 1.
    For every hour when the shop is closed and customers come, the penalty increases by 1.
    Return the earliest hour at which the shop must be closed to incur a minimum penalty.

    Example 1:
    Input: customers = "YYNY"
    Output: 2
    Explanation: 
    - Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
    - Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
    - Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
    - Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
    - Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
    Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> penalty(n + 1, 0);

        int totalY = 0;
        int totalN = 0;
        for (char c : customers) {
            if (c == 'Y') 
                totalY++;
            else 
                totalN++;
        }

        vector<int> prefixN(n + 1, 0);
        vector<int> suffixY(n + 1, 0);

        for (int i = 0; i < n; i++) 
            prefixN[i + 1] = prefixN[i] + (customers[i] == 'N' ? 1 : 0);

        for (int i = n - 1; i >= 0; i--) 
            suffixY[i] = suffixY[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        
        for (int j = 0; j <= n; j++) 
            penalty[j] = prefixN[j] + suffixY[j];

        int minPenalty = INT_MAX;
        int bestHour = 0;
        for (int j = 0; j <= n; j++) {
            if (penalty[j] < minPenalty) {
                minPenalty = penalty[j];
                bestHour = j;
            }
        }

        return bestHour;
    }
};