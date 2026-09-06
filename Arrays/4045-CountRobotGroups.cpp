/*
    You are given a strictly increasing integer array position, where position[i] is the initial position of the ith robot at time t = 0. You are also given an integer array 
    speed, where speed[i] is the constant speed of the ith robot in units per second, and an integer distance. Time is continuous and measured in seconds. A robot or group with
    speed v moves v * t units to the right over any interval of t seconds. Whenever the distance between two robots or groups becomes at most distance, they merge into a single
    group. If multiple robots or groups satisfy the merging condition at the same time, all merges happen simultaneously. In particular, every connected collection of robots or
    groups whose consecutive positions differ by at most distance merges into one group. After a merge, the resulting group takes the current position and speed of the 
    rightmost robot in that group. Once merged, robots never separate. Return the number of groups remaining after all possible merges have occurred.

    Example 1:
    Input: position = [1,5,6,20], speed = [4,3,2,3], distance = 1
    Output: 2
    Explanation: Initially, the groups are {R1}, {R2}, {R3}, and {R​​​​​​​4}. At t = 0, the robots R2 and R3 at positions 5 and 6, respectively, merge because they are 1 unit apart. 
    The resulting group moves with the position and speed of the rightmost robot R3. The groups are now {R1}, {R2, R3}, and {R​4}. Later at t = 2, the robot R1 catches up to the
    group {R2, R3} and merges with it. The groups are now {R1, R2, R3} and {R​4}. Thus, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        int prevSpeed = speed[n-1];
        int prevPos = position[n-1]; 

        int ans = 1;

        for(int i=n-2; i>=0; i--) {
            if(speed[i] > prevSpeed || prevPos - position[i] <= distance) 
                prevPos = position[i];
            else {
                ans++;
                prevSpeed = speed[i];
                prevPos = position[i];
            }
        }
        
        return ans;
    }
};