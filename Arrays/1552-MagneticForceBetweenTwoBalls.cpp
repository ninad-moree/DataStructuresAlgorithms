/*
    In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. 
    Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that 
    the minimum magnetic force between any two balls is maximum. Rick stated that magnetic force between two different balls at positions x and 
    y is |x - y|. Given the integer array position and the integer m. Return the required force.

    Example 1:
    Input: position = [1,2,3,4,7], m = 3
    Output: 3
    Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic 
    force is 3. We cannot achieve a larger minimum magnetic force than 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& arr, int m, int mid) {
        int cnt = 1;
        int last = arr[0];
        for(int i=0;i<arr.size();i++) {
            if(arr[i]-last >= mid) {
                cnt++;
                if(cnt==m) return true;
                last = arr[i];
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int maxi = -1;
        for(int i=0;i<position.size();i++) 
            maxi = max(maxi, position[i]);

        int s = 0;
        int e = maxi;
        int mid = s+(e-s)/2;

        int ans = -1;
        while(s<=e) {
            if(isPossible(position, m, mid)) {
                ans = mid;
                s=mid+1;
            }
            else 
                e = mid-1;
            mid = s+(e-s)/2;
        }
        return ans;
    }
};